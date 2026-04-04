#include "main.h"
/**
 * print_hex - print in base 16 with uppercase
 * @n: an integer
 *
 * Return: (count), number of characters printed
 */
int print_hex(unsigned int n)
{
	char *alphab = "0123456789ABCDEF";
	int count = 0;

	if (n >= 16)
		count = count + (print_hex(n / 16));
	write(1, &alphab[n % 16], 1);
	count++;
	return (count);
}
/**
 * print_hex_min - print in base 16 with lowercase
 * @n: an integer
 *
 * Return: (count), number of characters printed
 */
int print_hex_min(unsigned int n)
{
	char *alphab = "0123456789abcdef";
	int count = 0;

	if (n >= 16)
		count = count + (print_hex_min(n / 16));
	write(1, &alphab[n % 16], 1);
	count++;
	return (count);
}
/**
 * print_unsigned_nbretotext - print and converse positive number in text
 * @n: an integer
 *
 * Return: (count), number of characters printed
 */
int print_unsigned_nbretotext(unsigned int n)
{
	int count = 0;
	char c;

	if (n >= 10)
		count = count + print_unsigned_nbretotext(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	count++;
	return (count);
}
/**
 * print_b_eight - print in base 8
 * @n: an integer
 *
 * Return: (count), number of characters printed
 */
int print_b_eight(unsigned int n)
{
	int count = 0;
	char c;

	if (n >= 8)
		count = count + print_b_eight(n / 8);
	c = (n % 8) + '0';
	write(1, &c, 1);
	count++;
	return (count);
}
