#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * nbretotxt - Converts an integer to a string
 * @n: Integer to convert
 *
 * Converts an integer into its string representation. Handles negative
 * numbers and allocates memory dynamically for the resulting string.
 *
 * Return: Pointer to the resulting string, or NULL on failure
 */
int nbretotxt(int n)
{
	char nbre;
	char signe = '-';
	char *min = "-2147483648";
	int count = 0;

	if (n == INT_MIN)
	{
		while (*min != '\0')
		{
			count = count + write(1, min, 1);
			min++;
		}
		return (count);
	}
	if (n < 0)
	{
		n = -n;
		count = count + write(1, &signe, 1);
	}
	if (n / 10)
	{
		count = count + nbretotxt(n / 10);
	}
	nbre = (n % 10) + '0';
	count = count + write(1, &nbre, 1);
	return (count);
}
/**
 * get_function - Executes the function matching a format specifier
 * @c: Format specifier
 * @ap: Variadic arguments list
 *
 *
 * Finds the corresponding function for a specifier and executes it.
 *
 * Return: Number of characters printed, or 0 if not found
 */
int get_function(char c, va_list *ap)
{
	int j = 0;
	op_t print_flag[] = {
		{'c', print_char},
		{'i', print_int},
		{'d', print_int},
		{'s', print_string},
		{'%', print_percent},
		{'X', print_hex_upper},
		{'x', print_hex_lower},
		{'u', print_unsigned},
		{'o', print_octa},
		{0, NULL}
	};
	while (print_flag[j].op)
	{
		if (c == print_flag[j].op)
			return (print_flag[j].f(ap));
		j++;
	}
	write(1, "%", 1);
	write(1, &c, 1);
	return (2);
}

/**
 * _printf - Produces output according to a format string
 * @format: the format string to parse
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
	va_list ap;
	int i = 0, count = 0;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			count++;
			i++;
			continue;
		}
		i++;
		if (format[i] == '\0')
			return (count);
		count += get_function(format[i], &ap);
		i++;
	}
	va_end(ap);
	return (count);
}
