#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/**
 * get_function - Executes the function associated with a format specifier
 * @c: format specifier character
 * @ap: variadic arguments list
 *
 * This function searches for the corresponding function linked to the
 * given specifier and calls it with the provided variadic arguments.
 */
void get_function(char c, va_list ap)
{
	int j = 0;
	op_t print_flag[] = {
		{'c', print_char},
		{'i', print_int},
		{'d', print_int},
		{'f', print_double},
		{'s', print_string},
		{'%', print_pourcent},
		{0, NULL}
	};
	while (print_flag[j].op)
	{
		if (c == print_flag[j].op)
		{
			print_flag[j].f(&ap);
			break;
		}
		j++;
	}
}

/**
 * _printf - Produces output according to a format string
 * @format: string containing the format specifiers
 *
 * This function parses the format string and prints characters to the
 * standard output. When a '%' is encountered, it calls the appropriate
 * function associated with the specifier to print the corresponding
 * argument from the variadic list.
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, count = 0;
	va_list ap;

	va_start(ap, format);
	while (format && format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			count++;
		}
		else
		{
			i++;
			get_function(format[i], ap);
		}
		i++;
	}
	va_end(ap);
	return (count);
}
