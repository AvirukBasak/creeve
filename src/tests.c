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
bool test_filesys()
{
    bool flag = true;
    // mk_dummyfiles (3);
    string filepaths[3] = {
        "src/testing/file1.crv",
        "src/testing/file2.crv",
        "src/testing/file3.crv"
    };
    string fdp1 = fs_get_file_dirpath (filepaths[0]);
    if (strcmp (fdp1, "src/testing/")) {
        fprintf (stderr, "test: fdp1: %s, expect %s\n", fdp1, "src/testing/");
        flag = false;
    }
    free (fdp1);
    string fbn2 = fs_get_file_basename (filepaths[1]);
    if (strcmp (fbn2, "file2.crv")) {
        fprintf (stderr, "test: fbn2: %s, expect %s\n", fbn2, "file2.crv");
        flag = false;
    }
    free (fbn2);
    string fbnx3 = fs_get_file_basename_without_ext (filepaths[2]);
    if (strcmp (fbnx3, "file3")) {
        fprintf (stderr, "test: fbnx3: %s, expect %s\n", fbnx3, "file3");
        flag = false;
    }
    free (fbnx3);
    if (!flag) {
        return false;
    }
    return true;
}

int main (int argsc, string argsv[])
{
    bool test_success = false;
    test_success = test_filesys();
    if (!test_success) {
        printf ("Test FAILED\n");
    } else {
        printf ("Test SUCCESS\n");
    }
    return 0;
}
