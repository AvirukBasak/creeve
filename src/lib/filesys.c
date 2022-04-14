# include "filesys.h"

/**
 * @brief For a file path = "dira/dirb/dirc/file.xy", the function returns "dira/dirb/dirc/"
 *
 * @param path The path to function on
 * @return char* The directory path. NOTE that you must free() the returned value after usage.
 */
string fs_get_file_dirpath (string path)
{
    int i;
    string basename;
    for (i = strlen (path) - 1; i >= 0; i--) {
        if ((sys_is_Windows() && path[i] == '\\') || (sys_is_Unix() && path[i] == '/')) {
            break;
        }
    }
    size_t size = strlen (&path[strlen (path) - i]);
    basename = malloc (sizeof (char) * size + BUFFER_SIZE);
    if (basename == NULL) {
        outputs_err_exit ("null pointer error", E_NULLPTR);
    }
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
    int i;
    string basename;
    for (i = strlen (path) - 1; i >= 0; i--) {
        if ((sys_is_Windows() && path[i] == '\\') || (sys_is_Unix() && path[i] == '/')) {
            break;
        }
    }
    size_t size = strlen (&path[i]);
    basename = malloc (sizeof (char) * size + BUFFER_SIZE);
    if (basename == NULL) {
        outputs_err_exit ("null pointer error", E_NULLPTR);
    }
    strcpy (basename, &path[i]);
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
    int i, j;
    string basename;
    for (i = strlen (path) - 1; i >= 0; i--) {
        if ((sys_is_Windows() && path[i] == '\\') || (sys_is_Unix() && path[i] == '/')) {
            i++;
            break;
        }
    }
    for (j = strlen (path) - 1; j >= 0; j--) {
        if (path[i] == '.') {
            break;
        }
    }
    size_t size = strlen (&path[j - i + 1]);
    basename = malloc (sizeof (char) * size + BUFFER_SIZE);
    if (basename == NULL) {
        outputs_err_exit ("null pointer error", E_NULLPTR);
    }
    strncpy (basename, &path[i], size);
    return basename;
}
