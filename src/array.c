#include <stdio.h>
#include <stdlib.h>
#include "../include/array.h"

void initCharArray(CharArray *arr, size_t initialSize) {
    arr->array = malloc(initialSize * sizeof(char));
    arr->used = 0;
    arr->size = initialSize;
}

void insertCharArray(CharArray *arr, char element) {
    if(arr->size == arr->used) {
        arr->size++;
        arr->array = realloc(arr->array, arr->size * sizeof(char));
    }
    arr->array[arr->used++] = element;
}

void initTokenArray(TokenArray *arr, size_t initialSize) {
    arr->array = malloc(initialSize * sizeof(char));
    arr->used = 0;
    arr->size = initialSize;
}

void insertTokenArray(TokenArray *arr, struct Token element) {
    if(arr->size == arr->used) {
        arr->size++;
        arr->array = realloc(arr->array, arr->size * sizeof(struct Token));
    }
    arr->array[arr->used++] = element;
}

void freeTokenArray(TokenArray *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}

void freeCharArray(CharArray *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}