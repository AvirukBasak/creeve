/*
 * WARNING 1:
 * All functions MUST be prefixed w/ tokenizer_
 * Example: prototype for function that tokenizes may be
 *          string *tokenizer_tokenize (FILE *ptr)
 *
 * WARNING 2:
 * If a function uses *alloc, it's the job of the caller to free the memory.
 * Such a function HAS TO in its doc ask the caller to clear up the memory.
 * Same goes for closing of files (created file pointers);
 */

# include "../headers/headers.h"
# include "../headers/errcodes.h"

# ifndef TOKENIZER_H

    # define TOKENIZER_H 1

    /**
     * @brief Returns an array of strings containing tokens
     *
     * A token is defined as a keyword, identifier, operator, or symbol
     * A list of tokens will be provided in the README.md of the project
     *
     * @param ptr The pointer to the file whose code will be tokenized
     * @return char** A string array of tokens. NOTE that you must free() the returned value after usage.
     */
    string *tokenizer_tokenize (FILE *ptr);

# endif
