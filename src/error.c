#include <stdio.h>
#include "../include/error.h"

void error(int line, char message[]) {
    report(line, "", message);
}

void report(int line, char where[], char message[]) {
    printf("[Line %d] %s: %s \n", line, where, message);
}