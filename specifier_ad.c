#include "main.h"
#include <stdarg.h>
/**
 * print_hex_upper - Prints in hexadecimal in uppercase
 * @ap: pointer to the variadic arguments list
 *
 * Retrieves a string from the va_list and prints it.
 * If the string is NULL, prints "(null)".
 *
 * Return: Number of characters printed
 */
int print_hex_upper(va_list *ap)
{
	unsigned int n = va_arg(*ap, unsigned int);

	return (print_hex(n));
}
/**
 * print_hex_lower - Prints in hexadecimal in lowercase
 * @ap: pointer to the variadic arguments list
 *
 * Retrieves a string from the va_list and prints it.
 * If the string is NULL, prints "(null)".
 *
 * Return: Number of characters printed
 */
int print_hex_lower(va_list *ap)
{
	unsigned int n = va_arg(*ap, unsigned int);

	return (print_hex_min(n));
}
/**
 * print_unsigned - Prints an unsigned int
 * @ap: Variadic argument list containing the integer to print
 *
 * Retrieves an integer from the va_list, converts it to its string
 * representation, prints it, and returns the number of characters printed.
 *
 * Return: Number of characters printed
 */
int print_unsigned(va_list *ap)
{
	unsigned int n = va_arg(*ap, unsigned int);

	return (print_unsigned_nbretotext(n));
}
/**
 * print_octa - Prints in octadecimal
 * @ap: pointer to the variadic arguments list
 *
 * Retrieves a string from the va_list and prints it.
 * If the string is NULL, prints "(null)".
 *
 * Return: Number of characters printed
 */
int print_octa(va_list *ap)
{
	unsigned int n = va_arg(*ap, unsigned int);

	return (print_b_eight(n));
}

/**
 * print_bin - Prints in binary
 * @ap: pointer to the variadic arguments list
 *
 * Retrieves a string from the va_list and prints it.
 * If the string is NULL, prints "(null)".
 *
 * Return: Number of characters printed
 */
int print_bin(va_list *ap)
{
	unsigned int n = va_arg(*ap, unsigned int);

	return (print_binary_f(n));
}

