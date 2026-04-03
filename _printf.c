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
 * get_function - Executes the function matching a format specifier
 * @c: Format specifier
 * @ap: Variadic arguments list
 * @count: Number of printed characters
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
		{0, NULL}
	};
	while (print_flag[j].op)
	{
		if (c == print_flag[j].op)
			return (print_flag[j].f(ap));
		j++;
	}
		return (0);
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
	int i = 0, count = 0, printed = 0;
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
            printed = get_function(format[i], &ap);
			if (printed == 0)
			{
				write(1, "%", 1);
				write(1, &format[i], 1);
				count += 2;
			}
			else
				count += printed;
			}
		i++;
	}
	va_end(ap);
	return (count);
}

/**
 * main - Test function for _printf
 *
 * Return: Always 0
 */
int main(void)
{
	int len1, len2;

	printf("===== TEST CHAR =====\n");
	len1 = printf("printf: %c\n", 'A');
	len2 = _printf("_printf: %c\n", 'A');
	printf("len printf: %d | len _printf: %d\n\n", len1, len2);

	printf("===== TEST STRING =====\n");
	len1 = printf("printf: %s\n", "Hello World");
	len2 = _printf("_printf: %s\n", "Hello World");
	printf("len printf: %d | len _printf: %d\n\n", len1, len2);

	printf("===== TEST PERCENT =====\n");
	len1 = printf("printf: %%\n");
	len2 = _printf("_printf: %%\n");
	printf("len printf: %d | len _printf: %d\n\n", len1, len2);

	printf("===== TEST INTEGER =====\n");
	len1 = printf("printf: %d\n", 123);
	len2 = _printf("_printf: %d\n", 123);
	printf("len printf: %d | len _printf: %d\n\n", len1, len2);

	printf("===== TEST NEGATIVE INTEGER =====\n");
	len1 = printf("printf: %d\n", -456);
	len2 = _printf("_printf: %d\n", -456);
	printf("len printf: %d | len _printf: %d\n\n", len1, len2);

	printf("===== TEST ZERO =====\n");
	len1 = printf("printf: %d\n", 0);
	len2 = _printf("_printf: %d\n", 0);
	printf("len printf: %d | len _printf: %d\n\n", len1, len2);

	printf("===== TEST MULTIPLE FORMAT =====\n");
	len1 = printf("printf: %c %s %d %%\n", 'B', "Test", 42);
	len2 = _printf("_printf: %c %s %d %%\n", 'B', "Test", 42);
	printf("len printf: %d | len _printf: %d\n\n", len1, len2);

	printf("===== TEST EMPTY STRING =====\n");
	len1 = printf("printf: %s\n", "");
	len2 = _printf("_printf: %s\n", "");
	printf("len printf: %d | len _printf: %d\n\n", len1, len2);

	printf("===== TEST NULL STRING =====\n");
	len1 = printf("printf: %s\n", (char *)NULL);
	len2 = _printf("_printf: %s\n", (char *)NULL);
	printf("len printf: %d | len _printf: %d\n\n", len1, len2);

	printf("===== TEST EDGE CASE =====\n");
	len1 = printf("printf: %d %d %d\n", 2147483647, -2147483648, 999999);
	len2 = _printf("_printf: %d %d %d\n", 2147483647, -2147483648, 999999);
	printf("len printf: %d | len _printf: %d\n\n", len1, len2);

	return (0);
}
