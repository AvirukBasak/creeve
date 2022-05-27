# include "filesys.h"
# include "outputs.h"
# include "system.h"
# include "errhandle.h"

/**
 * @brief For a file path = "dira/dirb/dirc/file.xy", the function returns "dira/dirb/dirc/"
 *
 * @param path The path to function on
 * @return char* The directory path. NOTE that you must free() the returned value after usage.
 */
string fs_get_file_dirpath (string path)
{
    uqword i, size;
    string basename;
    for (i = strlen (path) - 1; i >= 0; i--) {
        if ((sys_is_Windows() && path[i] == '\\') || (sys_is_Unix() && path[i] == '/')) {
            i++;
            break;
        }
    }
    size = strlen (&path[strlen (path) - i]);
    basename = (string) malloc (sizeof (char) * size + BUFFER_SIZE);
    err_nullptr (basename);
    strncpy (basename, path, size);
    return basename;
}

/**
 * @brief For a file path = "dira/dirb/dirc/file.xy", the function returns "file.xy"
 *
 * @param path The path to function on
 * @return char* The basename. NOTE that you must free() the returned value after usage.
 */
string fs_get_file_basename (string path)
{
    uqword i, size;
    string basename;
    for (i = strlen (path) - 1; i >= 0; i--) {
        if ((sys_is_Windows() && path[i] == '\\') || (sys_is_Unix() && path[i] == '/')) {
            break;
        }
    }
    size = strlen (&path[i]);
    basename = (string) malloc (sizeof (char) * size + BUFFER_SIZE);
    err_nullptr (basename);
    strcpy (basename, &path[i+1]);
    return basename;
}

/**
 * @brief For a file path = "dira/dirb/dirc/file.xy", the function returns "file"
 *
 * @param path The path to function on
 * @return char* The basename without extension. NOTE that you must free() the returned value after usage.
 */
string fs_get_file_basename_without_ext (string path)
{
    uqword i, j, size;
    string basename;
    for (i = strlen (path) - 1; i >= 0; i--) {
        if ((sys_is_Windows() && path[i] == '\\') || (sys_is_Unix() && path[i] == '/')) {
            i++;
            break;
        }
    }
    for (j = strlen (path) - 1; j >= 0; j--) {
        if (path[j] == '.') {
            break;
        }
    }
    size = strlen (&path[j - i + 1]);
    basename = (string) malloc (sizeof (char) * size + BUFFER_SIZE);
    err_nullptr (basename);
    strncpy (basename, &path[i], size);
    return basename;
}
