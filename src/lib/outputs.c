# include "outputs.h"

/**
 * @brief Prints error message to stderr and exits with error code
 *
 * @param message The message to print
 * @param err_code The exit code
 */
void outputs_err_exit (const string message, byte err_code)
{
    fprintf (stderr, "creeve: error: %s\n", message);
    exit (err_code);
}
