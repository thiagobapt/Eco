#ifndef ERROR_H
#define ERROR_H

char* formatString(char str[], ...);

void error(int line, char message[]);

void report(int line, char where[], char message[]);

#endif