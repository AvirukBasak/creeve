/*
 * WARNING 1:
 * All functions MUST be prefixed w/ err_
 * Example: prototype for function that prints error may be
 *          string *err_output (FILE *ptr)
 *
 * WARNING 2:
 * If a function uses *alloc, it's the job of the caller to free the memory.
 * Such a function HAS TO in its doc ask the caller to clear up the memory.
 * Same goes for closing of files (created file pointers);
 */

# include "../headers/headers.h"
# include "../headers/errcodes.h"

# ifndef ERRHANDLE_H

    # define ERRHANDLE_H 1

    /**
     * @brief Exits if pointer is NULL.
     * @param ptr The pointer to validate
     */
    void err_nullptr (void* ptr);

# endif
