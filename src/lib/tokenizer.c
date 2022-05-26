# include "tokenizer.h"
# include "errhandle.h"

/**
 * @brief Returns an array of strings containing tokens
 *
 * A token is defined as a keyword, identifier, operator, or symbol
 * A list of tokens will be provided in the README.md of the project
 *
 * @param ptr The pointer to the file whose code will be tokenized
 * @return char** A string array of tokens. NOTE that you must free() the returned value after usage.
 */
string *tokenizer_tokenize (FILE *ptr)
{
    return NULL;
}

void tokenizer_freetokens (string *tokens, uqword tokens_count)
{
    uqword i;
    err_nullptr (tokens);
    for (i = 0; i < tokens_count; i++) {
        err_nullptr (tokens[i]);
        free (tokens[i]);
    }
    free (tokens);
}
