# include "filesys.h"

/**
 * @brief For a file path = "dira/dirb/dirc/file.xy", the function returns "dira/dirb/dirc/"
 *
 * @param path The path to function on
 * @return char* The directory path. NOTE that you must free() the returned value after usage.
 */
string fs_get_file_dirpath (string path)
{
    return NULL;
}

/**
 * @brief For a file path = "dira/dirb/dirc/file.xy", the function returns "file.xy"
 *
 * @param path The path to function on
 * @return char* The basename. NOTE that you must free() the returned value after usage.
 */
string fs_get_file_basename (string path)
{
    return NULL;
}

/**
 * @brief For a file path = "dira/dirb/dirc/file.xy", the function returns "file"
 *
 * @param path The path to function on
 * @return char* The basename without extension. NOTE that you must free() the returned value after usage.
 */
string fs_get_file_basename_without_ext (string path)
{
    return NULL;
}
