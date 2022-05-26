# include "rsvtokens.h"

const string Keywords [KEYWORDS_COUNT] = {

    // added keywords
    "namespace", "class", "this", "new",

    // original C keywords
    "char",     "int",      "float",  "double",   "signed",  "unsigned", "short",   "long",
    "void",     "const",    "auto",   "register", "static",  "extern",   "typedef", "return",
    "if",       "else",     "switch", "case",     "default", "for",      "do",      "while",
    "break",    "continue", "goto",   "sizeof",   "typeof",  "union",    "enum",    "struct",
    "volatile", "asm"
};

// lower the index, higher the priority
const string Operators [OPERATORS_COUNT] = {
    "::", "++",  "--",  ".",  "->", "!",  "~",  "/",
    "%",  "*",   "+",   "-",  "<<", ">>", "<",  "<=",
    ">",  ">=",  "==",  "!=", "&",  "^",  "|",  "&&",
    "||", "?",   ":",   "=",  "+=", "-=", "*=", "/=",
    "%=", "<<=", ">>=", "&=", "^=", "|="
};

const string Symbols [SYMBOLS_COUNT] = {
    "(", ")",  "{",  "}", "[", "]",  ",",  ";",
    "'", "\""
};

// "#", "//", "/*", "*/"
