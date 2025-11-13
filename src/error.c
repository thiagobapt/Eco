#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "../include/error.h"

void error(int line, char message[]) {
    report(line, "", message);
}

void report(int line, char where[], char message[]) {
    printf("\n[Line %d] %s: %s \n", line, where, message);
}