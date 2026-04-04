#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
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
	int (*f)(va_list *);
} op_t;

int _printf(const char * const format, ...);
int get_function(char c, va_list *ap);
int print_char(va_list *ap);
int print_int(va_list *ap);
int print_string(va_list *ap);
int print_percent(va_list *ap);
int nbretotxt(int n);
int print_hex_upper(va_list *ap);
int print_hex(unsigned int n);
int print_hex_lower(va_list *ap);
int print_hex_min(unsigned int n);
int print_unsigned(va_list *ap);
int print_unsigned_nbretotext(unsigned int n);
int print_octa(va_list *ap);
int print_b_eight(unsigned int n);

#endif
