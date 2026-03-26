#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
/**
 * print_char - Affiche un caractère
 * @ap: Liste d'arguments variadiques contenant le caractère à afficher
 *
 * Récupère un int depuis la va_list et l'affiche comme un caractère.
 */
void print_char(va_list *ap)
{
	printf("%c", va_arg(*ap, int));
}

/**
 * print_int - Affiche un entier
 * @ap: Liste d'arguments variadiques contenant l'entier à afficher
 *
 * Récupère un int depuis la va_list et l'affiche.
 */
void print_int(va_list *ap)
{
	printf("%d", va_arg(*ap, int));
}
/**
 * print_double - Affiche un nombre à virgule flottante
 * @ap: Liste d'arguments variadiques contenant le double à afficher
 *
 * Récupère un double depuis la va_list et l'affiche.
 */
void print_double(va_list *ap)
{
	printf("%f", va_arg(*ap, double));
}
/**
 * print_string - Affiche une chaîne de caractères
 * @ap: Liste d'arguments variadiques contenant la chaîne à afficher
 *
 * Récupère un char* depuis la va_list et l'affiche.
 * Si la chaîne est NULL, affiche "(nil)".
 */
void print_string(va_list *ap)
{
	char *str = va_arg(*ap, char *);

	if (str == NULL)
		str = "(nil)";
	printf("%s", str);
}
/**
 * _printf - custom printf function
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, j = 0, count = 0;
	va_list ap;
	op_t print_flag[] = {
		{'c', print_char},
		{'i', print_int},
		{'d', print_int},
		{'f', print_double},
		{'s', print_string},
		{0, NULL}
	};

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
//			if (format[i] == '%')
//			{
//				write(1, "%", 1);
//				count++;
//				i++;
//				continue;
//			}
			while (print_flag[j].op)
			{
				if (format[i] == print_flag[j].op)
				{
					print_flag[j].f(&ap);
					break;
				}
				j++;
			}
		}
		i++;
	}
	va_end(ap);
	return (count);
}
