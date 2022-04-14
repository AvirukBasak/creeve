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

    // create the llist data structure
    File file_node = (File) malloc (1 * sizeof (struct File));
    file_node->ptr = NULL;
    file_node->path = NULL;
    file_node->next = NULL;

    File new_file_node = NULL;

    /* going through list of file paths in argsv
     * the aim is to organise file paths and pointers in one struct
     */
    new_file_node = file_node;
    for (udword i = 1; i < argsc; i++) {
        if (new_file_node == NULL) {
            outputs_err_exit ("null pointer error", E_NULLPTR);
        }
        // we are able to assign the arguments to the File struct as argsv is not popped till main pop (program's end)
        new_file_node->path = argsv[i];
        new_file_node->ptr = fopen (argsv[i], "rb");
        new_file_node->next = NULL;
        // if file ptr is null
        if (new_file_node->ptr == NULL) {
            // TODO: abstract out variable error messages
            string err_msg = "couldn't read ";
            // allocate a new string to hold the full err msg
            string err_msg2 = (string) malloc (sizeof (char) * (strlen (err_msg) + strlen (argsv [i])));
            // copy the err msg to new string
            strcpy (err_msg2, err_msg);
            // concat file path to err msg
            strcat (err_msg2, argsv [i]);
            // display err and exit
            outputs_err_exit (err_msg2, E_CLIARGS);
            // good practice to always free, never executed
            free (err_msg2);
        }
        // do not create new node if this is the last file path argument
        if (i == argsc - 1)
            break;
        new_file_node->next = (File) malloc (1 * sizeof (struct File));
        new_file_node = new_file_node->next;
        new_file_node->ptr = NULL;
        new_file_node->path = NULL;
        new_file_node->next = NULL;
    }

    /* this loop goes through each file, and runs the compiler on that file
     * generates c code and writes to a .c file
     */
    new_file_node = file_node;
    while (new_file_node != NULL) {
        string path = new_file_node->path;
        FILE *ptr = new_file_node->ptr;

        // gets c code from crv code by compilation
        string compiled_c_code = compiler_compile (ptr);

        // gets file path, and file basename without the extension
        string c_code_path = fs_get_file_dirpath (path);
        string c_code_filename = fs_get_file_basename_without_ext (path);
 
        // same as: string c_code_fullpath = new string (c_code_path + "/" + c_code_filename + ".c");
        string c_code_fullpath = (string) malloc (strlen (c_code_path) + strlen (c_code_filename) + strlen (".c") + BUFFER_SIZE);
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

        c_file_ptr = NULL;
        compiled_c_code = NULL;
        c_code_path = NULL;
        c_code_filename = NULL;
        c_code_fullpath = NULL;

        new_file_node = new_file_node->next;
    }

    return 0;
}
