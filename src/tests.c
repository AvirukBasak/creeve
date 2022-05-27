# include "headers/headers.h"
# include "headers/errcodes.h"
# include "lib/compiler.h"
# include "lib/errhandle.h"
# include "lib/filesys.h"
# include "lib/outputs.h"
# include "lib/rsvtokens.h"
# include "lib/system.h"
# include "lib/tokenizer.h"

// this is gonna be 🦆-ing slow
void mk_dummyfiles (udword count)
{
    udword i;
    if (count > 50) {
        count = 50;
    }
    for (i = 1; i <= count; i++) {
        string halfpath = "src/testing/file";
        char filenum[4] = {0};
        sprintf (filenum, "%d", i);
        string ext = ".crv";
        string filepath = (string) calloc (BUFFER_SIZE + (
              strlen (ext)
            + strlen (halfpath)
            + strlen (filenum)
        ), sizeof (char));
        strcpy (filepath, halfpath);
        strcat (filepath, filenum);
        strcat (filepath, ext);
        FILE *file = fopen (filepath, "wb");
        free (filepath);
        fprintf (file, "%s", "garbage");
        fclose (file);
    }
}

// section: testing filesys.h
bool test_filesys (int argsc, string filepaths[])
{
    return false;
}

int main (int argsc, string argsv[])
{
    mk_dummyfiles (3);
    string filepaths[3] = {
        "src/testing/file1.crv",
        "src/testing/file2.crv",
        "src/testing/file3.crv"
    };
    test_filesys (3, filepaths);
    return 0;
}