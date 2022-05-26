# include "errhandle.h"
# include "outputs.h"

/**
 * @brief Exits if pointer is NULL.
 * @param ptr The pointer to validate
 */
void err_nullptr (void* ptr)
{
    if (ptr == NULL) {
        outputs_err_exit ("null pointer error", E_NULLPTR);
    }
}
