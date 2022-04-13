/*
 * WARNING 1:
 * All functions MUST be prefixed w/ fs_
 * Example: prototype for function that gets dir path of a file may be
 *          string fs_get_file_dirpath (char *path)
 *
 * WARNING 2:
 * If a function uses *alloc, it's the job of the caller to free the memory.
 * Such a function HAS TO in its doc ask the caller to clear up the memory.
 * Same goes for closing of files (created file pointers);
 */

# include "../headers/headers.h"
# include "../headers/errcodes.h"

# ifndef FILESYS_H

    # define FILESYS_H 1

    // linked list to hold data of files
    typedef struct File {
        FILE *ptr;
        string path;
        struct File *next;
    } *File;

    /**
     * @brief For a file path = "dira/dirb/dirc/file.xy", the function returns "dira/dirb/dirc/"
     *
     * @param path The path to function on
     * @return char* The directory path. NOTE that you must free() the returned value after usage.
     */
    string fs_get_file_dirpath (string path);

    /**
     * @brief For a file path = "dira/dirb/dirc/file.xy", the function returns "file.xy"
     *
     * @param path The path to function on
     * @return char* The basename. NOTE that you must free() the returned value after usage.
     */
    string fs_get_file_basename (string path);

    /**
     * @brief For a file path = "dira/dirb/dirc/file.xy", the function returns "file"
     *
     * @param path The path to function on
     * @return char* The basename without extension. NOTE that you must free() the returned value after usage.
     */
    string fs_get_file_basename_without_ext (string path);

# endif
