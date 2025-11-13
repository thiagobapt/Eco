#ifndef ARRAY_H
#define ARRAY_H
#include "token.h"
#include <stdio.h>

typedef struct {
  char *array;
  size_t used;
  size_t size;
} CharArray;

typedef struct {
  struct Token *array;
  size_t used;
  size_t size;
} TokenArray;

void initCharArray(CharArray *arr, size_t initialSize);

void insertCharArray(CharArray *arr, char element);

void initTokenArray(TokenArray *arr, size_t initialSize);

void insertTokenArray(TokenArray *arr, struct Token element);

void freeTokenArray(TokenArray *a);

void freeCharArray(CharArray *a);

#endif