#include "main.h"
#include <stdarg.h>
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
