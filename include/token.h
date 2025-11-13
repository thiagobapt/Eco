#ifndef TOKEN_H
#define TOKEN_H

#include "tokenType.h"
#include "array.h"

struct Token {
    TokenType type;
    struct CharArray *lexeme;
    int line;
};

#endif