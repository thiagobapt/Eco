#include <stdlib.h>
#include <stdbool.h>
#include "../include/token.h"
#include "../include/array.h"
#include "../include/error.h"
#include "../include/scanner.h"
#include <string.h>

size_t srcSize;
size_t i;
size_t line = 1;

const int initialSize = 100;

TokenArray arr;
CharArray *src;

bool isAtEnd() {
    return i == srcSize;
}

char peek() {
    if(isAtEnd()) {
        return "\0";
    }
    return src->array[i + 1];
}

bool match(char expected) {
    if(isAtEnd()) {
        return false;
    }

    if(peek() != expected) {
        return false;
    }

    i++;

    return true;
}


void addToken(TokenType t, TokenArray *arr) {
    struct Token token;

    token.type = t;

    insertTokenArray(arr, token);
}

void scanToken(char c, TokenArray *arr) {
    printf("%c", c);
    switch (c) {
        case '(': addToken(LEFT_PAREN, arr); break;
        case ')': addToken(RIGHT_PAREN, arr); break;
        case '{': addToken(LEFT_BRACE, arr); break;
        case '}': addToken(RIGHT_BRACE, arr); break;
        case ',': addToken(COMMA, arr); break;
        case '.': addToken(DOT, arr); break;
        case '-': addToken(MINUS, arr); break;
        case '+': addToken(PLUS, arr); break;
        case ';': addToken(SEMICOLON, arr); break;
        case '*': addToken(STAR, arr); break;
        case '!':
            addToken(match('=') ? BANG_EQUAL : BANG, arr);
            break;
        case '=':
            addToken(match('=') ? EQUAL_EQUAL : EQUAL, arr);
            break;
        case '<':
            addToken(match('=') ? LESS_EQUAL : LESS, arr);
            break;
        case '>':
            addToken(match('=') ? GREATER_EQUAL : GREATER, arr);
            break;
        case ' ':
        case '\r':
        case '\t':
            // Ignore whitespace.
            break;
        case '\n':
            line++;
            break;
        default:
            error(line, formatString("Unexpected character: ", c));
            exit(65);
    }
}

TokenArray scan(CharArray *characters) {

    src = characters;
    
    initTokenArray(&arr, initialSize);

    size_t srcSize = src->size;

    for (i = 0; i < srcSize; i++) {
        scanToken(src->array[i], &arr);
    }

    freeCharArray(src);
    
    return arr;
}