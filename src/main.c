#include <stdio.h>
#include <stdbool.h>
#include "../include/error.h"
#include "../include/array.h"
#include "../include/scanner.h"

int main() {
    FILE *fptr = fopen("test.eco", "r");

    bool hadError = false;

    if(fptr == NULL) {
        printf("Couldn't find file! \n");
        return 1;
    }

    CharArray characters;

    initCharArray(&characters, 100);

    const int BUFFER_SIZE = 1;

    char buffer[BUFFER_SIZE];

    while(fgets(buffer, BUFFER_SIZE + 1, fptr)) {
        insertCharArray(&characters, buffer[0]);
    }

    //characters is freed in scan
    TokenArray tokens = scan(&characters);

    fclose(fptr);

    printf("\n");

    freeTokenArray(&tokens);

    if(hadError) {
        return 65;
    }

    return 0;
}

