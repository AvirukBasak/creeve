/*
 * WARNING 1:
 * All functions MUST be prefixed w/ outputs_
 * Example: prototype for function that prints errors may be
 *          void outputs_err_exit (string message, byte err_code);
 *
 * WARNING 2:
 * If a function uses *alloc, it's the job of the caller to free the memory.
 * Such a function HAS TO in its doc ask the caller to clear up the memory.
 * Same goes for closing of files (created file pointers);
 */

# include "../headers/headers.h"
# include "../headers/errcodes.h"

# ifndef OUTPUTS_H

    # define OUTPUTS_H 1

    /**
     * @brief Prints error message to stderr and exits with error code
     *
     * @param message The message to print
     * @param err_code The exit code
     */
    void outputs_err_exit (string message, byte err_code);

# endif
