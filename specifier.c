#include <unistd.h>
#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
/**
 * print_char - Prints a character
 * @ap: pointer to the variadic arguments list
 *
 * This function retrieves a character from the variadic arguments
 * and prints it to the standard output.
 */
void print_char(va_list *ap)
{
	char c = va_arg(*ap, int);

	write(1, &c, 1);
}

/**
 * print_int - Prints an integer
 * @ap: pointer to the variadic arguments list
 *
 * This function retrieves an integer from the variadic arguments
 * and prints it to the standard output.
 */
void print_int(va_list *ap)
{
	printf("%d", va_arg(*ap, int));
}
/**
 * print_double - Prints a floating-point number
 * @ap: pointer to the variadic arguments list
 *
 * This function retrieves a double from the variadic arguments
 * and prints it to the standard output.
 */
void print_double(va_list *ap)
{
	printf("%f", va_arg(*ap, double));
}
/**
 * print_pourcent - Prints a percent sign
 * @ap: pointer to the variadic arguments list
 *
 * This function prints the '%' character to the standard output.
 * The variadic argument list is unused but kept for consistency
 * with other printing functions.
 */
void print_pourcent(va_list *ap)
{
	write(1, "%", 1);
}
/**
 * print_string - Prints a string
 * @ap: pointer to the variadic arguments list
 *
 * This function retrieves a string from the variadic arguments
 * and prints it character by character. If the string is NULL,
 * it prints "(null)".
 */
void print_string(va_list *ap)
{
	char *str = va_arg(*ap, char *);
	int len = 0;

	if (str == NULL)
		str = "(nil)";
	do {
		write(1, str, 1);
	} while (*str++);
}
