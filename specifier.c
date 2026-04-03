#include "main.h"
#include <stdarg.h>
/**
 * print_char - Prints a character
 * @ap: Variadic argument list containing the character to print
 *
 * Retrieves a character from the va_list (as an int), prints it
 * using write, and returns the number of characters printed.
 *
 * Return: Always 1 (one character printed)
 */
int print_char(va_list *ap)
{
	char c = va_arg(*ap, int);

	write(1, &c, 1);
	return (1);
}

/**
 * print_int - Prints an integer
 * @ap: Variadic argument list containing the integer to print
 *
 * Retrieves an integer from the va_list, converts it to its string
 * representation, prints it, and returns the number of characters printed.
 *
 * Return: Number of characters printed
 */
int print_int(va_list *ap)
{
	int n = 0;

	n = va_arg(*ap, int);

	return (nbretotxt(n));
}
/**
 * print_percent - Prints a percent sign
 * @ap: pointer to the variadic arguments list
 *
 * Prints the '%' character using write.
 *
 * Return: Always 1 (one character printed)
 */
int print_percent(va_list *ap)
{
	char c = va_arg(*ap, int);

	write(1, &c, 1);
	return (1);
}
/**
 * print_string - Prints a string
 * @ap: pointer to the variadic arguments list
 *
 * Retrieves a string from the va_list and prints it.
 * If the string is NULL, prints "(null)".
 *
 * Return: Number of characters printed
 */
int print_string(va_list *ap)
{
	char *str = va_arg(*ap, char *);
    int count = 0;

	if (str == NULL)
		str = "(nil)";
	do {
		write(1, str, 1);
        count++;
	} while (*str++);
	return (count);
}
