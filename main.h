#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
/**
 * struct op_s - Associates a format specifier with a function
 * @op: format specifier character (e.g. 'c', 's', 'd')
 * @f: pointer to the function that handles the specifier
 *
 * This structure is used to map each format specifier to its
 * corresponding printing function.
 */
typedef struct op_s
{
	char op;
	void (*f)(va_list *);
} op_t;

int _printf(const char * const format, ...);
void print_char(va_list *ap);
void print_int(va_list *ap);
void print_double(va_list *ap);
void print_string(va_list *ap);

#endif
