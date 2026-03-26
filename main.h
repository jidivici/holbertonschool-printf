#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>

int _putchar(char c);
int _strlen(char *str);
int _printf(const char *format, ...);
void print_char(va_list *ap);
void print_int(va_list *ap);
void print_double(va_list *ap);
void print_string(va_list *ap);
void print_all(const char * const format, ...);

#endif
