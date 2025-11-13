#include <stdlib.h>
#include <stdbool.h>
#include "../include/token.h"
#include "../include/array.h"

#include "../include/scanner.h"

size_t srcSize;
size_t i;

const int initialSize = 100;

TokenArray arr;

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
    }
}

bool isAtEnd() {
    return i == srcSize;
}

TokenArray scan(CharArray *src) {
    initTokenArray(&arr, initialSize);

    size_t srcSize = src->size;

    for (i = 0; i < srcSize; i++) {
        scanToken(src->array[i], &arr);
    }

    freeCharArray(src);
    
    return arr;
}