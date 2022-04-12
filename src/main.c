# include "headers/headers.h"
# include "headers/errcodes.h"

# include "lib/filesys.h"
# include "lib/outputs.h"
# include "lib/compiler.h"

int main (int argsc, string argsv[])
{
    if (argsc < 2) {
        outputs_err_exit ("no arguments provided", E_CLIARGS);
    }

    File *files_array = NULL;

    /* going through list of file paths in argsv
     * the aim is to organise file paths and pointers in one struct
     */
    for (udword i = 1; i < argsc - 1; i++) {
        files_array = (File *) realloc (files_array, i * sizeof (File));
        if (files_array == NULL) {
            outputs_err_exit ("null pointer error", E_NULLPTR);
        }
        // we are able to assign the arguments to the File struct as argsv is not popped till main pop (program's end)
        files_array [i - 1]->path = argsv[i];
        files_array [i - 1]->ptr = fopen (argsv[i], "rb");
        // if file ptr is null
        if (files_array [i - 1]->ptr == NULL) {
            // TODO: abstract out variable error messages
            string err_msg = "couldn't read ";
            // allocate a new string to hold the full err msg
            char *err_msg2 = malloc (sizeof (char) * (strlen (err_msg) + strlen (argsv [i])));
            // copy the err msg to new string
            strcpy (err_msg2, err_msg);
            // concat file path to err msg
            strcat (err_msg2, argsv [i]);
            // display err and exit
            outputs_err_exit (err_msg2, E_CLIARGS);
            // good practice to always free, never executed
            free (err_msg2);
        }
    }

    /* this loop goes through each file, and runs the compiler on that file
     * generates c code and writes to a .c file
     */
    for (udword i = 0; i < argsc - 2; i++) {
        string path = files_array[i]->path;
        FILE *ptr = files_array[i]->ptr;

        // gets c code from crv code by compilation
        string compiled_c_code = compiler_compile (ptr);

        // gets file path, and file basename without the extension
        string c_code_path = fs_get_file_dirpath (path);
        string c_code_filename = fs_get_file_basename_without_ext (path);
        int buffer_space = 16;
 
        // same as: string c_code_fullpath = new string (c_code_path + "/" + c_code_filename + ".c");
        string c_code_fullpath = malloc (strlen (c_code_path) + strlen (c_code_filename) + strlen (".c") + buffer_space);
        strcpy (c_code_fullpath, c_code_path);
        strcat (c_code_fullpath, "/");
        strcat (c_code_fullpath, c_code_filename);
        strcat (c_code_fullpath, ".c");

        // opens a new file and writes the c code into it
        FILE *c_file_ptr = fopen (c_code_fullpath, "wb");
        fprintf (c_file_ptr, "%s", compiled_c_code);

        // closing file and freeing allocated memory
        fclose (c_file_ptr);
        free (compiled_c_code);
        free (c_code_path);
        free (c_code_filename);
        free (c_code_fullpath);
    }

    return 0;
}
