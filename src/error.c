#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "../include/error.h"

char* formatString(char str[], ...) {
    va_list args;

    char *buffer = (char *)malloc(256 * sizeof(char));
    size_t usedBufferSize = 0;

    va_start(args, str);

    char* arg;

    while((arg = va_arg(args, char *)) != 0) {

        size_t prevSize = usedBufferSize;

        usedBufferSize = usedBufferSize + (sizeof(arg) * sizeof(char));
        printf("\n%p", arg);
        printf("\nSize of buffer: %ld", usedBufferSize);
        printf("\nSize of arg: %ld", (size_t) (sizeof(arg) * sizeof(char)));

        buffer = (char *)realloc(buffer, usedBufferSize);

        for (size_t i = 0; i < sizeof(arg); i++) {
            printf("\n%ld", (prevSize / sizeof(char)) + i);
            printf("%c", arg[i]);
            // buffer[(prevSize / sizeof(char)) + i] = arg[i];
        }
        

        break;
    }
    
    va_end(args);

    return buffer;
}

void error(int line, char message[]) {
    report(line, "", message);
}

void report(int line, char where[], char message[]) {
    printf("\n[Line %d] %s: %s \n", line, where, message);
}