#include "main.h"
#include <stdarg.h>
/**
 * print_char - Prints a character
 * @ap: pointer to the variadic arguments list
 *
 * This function retrieves a character from the variadic arguments
 * and prints it to the standard output.
 */
int print_char(va_list *ap)
{
	char c = va_arg(*ap, int);

	write(1, &c, 1);
    return (0);
}

/**
 * print_int - Prints an integer
 * @ap: pointer to the variadic arguments list
 *
 * This function retrieves an integer from the variadic arguments
 * and prints it to the standard output.
 */
int print_int(va_list *ap)
{
	int n = 0;

	n = va_arg(*ap, int);

	return (nbretotxt(n));
}
/**
 * print_double - Prints a floating-point number
 * @ap: pointer to the variadic arguments list
 *
 * This function retrieves a double from the variadic arguments
 * and prints it to the standard output.
 */
int print_double(va_list *ap)
{
	printf("%f", va_arg(*ap, double));
    return (0);
}
/**
 * print_pourcent - Prints a percent sign
 * @ap: pointer to the variadic arguments list
 *
 * This function prints the '%' character to the standard output.
 * The variadic argument list is unused but kept for consistency
 * with other printing functions.
 */
int print_pourcent(va_list *ap)
{
	char c = va_arg(*ap, int);
    write(1, &c, 1);
    return (0);
}
/**
 * print_string - Prints a string
 * @ap: pointer to the variadic arguments list
 *
 * This function retrieves a string from the variadic arguments
 * and prints it character by character. If the string is NULL,
 * it prints "(null)".
 */
int print_string(va_list *ap)
{
	char *str = va_arg(*ap, char *);

	if (str == NULL)
		str = "(nil)";
	do {
		write(1, str, 1);
	} while (*str++);
    return (0);
}
