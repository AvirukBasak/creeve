/*
 * WARNING 1:
 * All functions MUST be prefixed w/ compiler_
 * Example: prototype for function that compiles may be
 *          string compiler_compile (FILE *ptr)
 *
 * WARNING 2:
 * If a function uses *alloc, it's the job of the caller to free the memory.
 * Such a function HAS TO in its doc ask the caller to clear up the memory.
 * Same goes for closing of files (created file pointers);
 */

# include "../headers/headers.h"
# include "../headers/errcodes.h"

# ifndef COMPILER_H

    # define COMPILER_H 1

    /**
     * @brief Compiles code in file and returns c code
     *
     * @param ptr The FILE pointer to the file to be compiled
     * @return char* The c code. NOTE that you must free() the returned value after usage.
     */
    string compiler_compile (FILE *ptr);

# endif
