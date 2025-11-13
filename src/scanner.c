#include <stdlib.h>
#include <stdbool.h>
#include "../include/token.h"
#include "../include/array.h"
#include "../include/error.h"
#include "../include/scanner.h"
#include <string.h>

size_t srcSize;
size_t currentPos;
size_t line = 1;
char currentChar;

const int initialSize = 100;

TokenArray tokens;
CharArray *src;

bool isAtEnd() {
    return currentPos == srcSize;
}

void advance() {
    if(isAtEnd()) {
        currentChar = '\0';
        return;
    }

    currentChar = src->array[currentPos];
    
    currentPos++;
}

char peek() {
    if(isAtEnd()) {
        return "\0";
    }
    return src->array[currentPos + 1];
}

bool match(char expected) {
    if(isAtEnd()) {
        return false;
    }

    if(peek() != expected) {
        return false;
    }

    currentPos++;

    return true;
}


void addToken(TokenType t) {
    struct Token token;

    token.type = t;

    insertTokenArray(&tokens, token);
}

void string() {
    size_t start = currentPos;

    while (peek() != '"' && !isAtEnd()) {
        printf("%c", currentChar);
        if(peek() == '\n') {
            line++;
        }
        advance();
    }

    if(isAtEnd()) {
        error(line, "Unterminated string");
        exit(65);
    }

    size_t stringLength = currentPos - start;

    char string[stringLength];

    for (size_t i = start + 1; i < currentPos - 1; i++) {
        string[i - start] = src->array[i];
    }

    printf("%s", string);
    
}

void scanToken() {
    advance();

    char c = currentChar;

    // printf("%c", c);

    switch (c) {
        case '(': addToken(LEFT_PAREN); break;
        case ')': addToken(RIGHT_PAREN); break;
        case '{': addToken(LEFT_BRACE); break;
        case '}': addToken(RIGHT_BRACE); break;
        case ',': addToken(COMMA); break;
        case '.': addToken(DOT); break;
        case '-': addToken(MINUS); break;
        case '+': addToken(PLUS); break;
        case ';': addToken(SEMICOLON); break;
        case '*': addToken(STAR); break;
        case '!':
            addToken(match('=') ? BANG_EQUAL : BANG);
            break;
        case '=':
            addToken(match('=') ? EQUAL_EQUAL : EQUAL);
            break;
        case '<':
            addToken(match('=') ? LESS_EQUAL : LESS);
            break;
        case '>':
            addToken(match('=') ? GREATER_EQUAL : GREATER);
            break;
        case '"':
            string();
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
            error(line, "Unexpected character");
            exit(65);
    }
}

TokenArray scan(CharArray *characters) {

    src = characters;
    
    initTokenArray(&tokens, initialSize);

    srcSize = src->size;

    while (isAtEnd() == false) {
        scanToken();
    }

    freeCharArray(src);
    
    return tokens;
}