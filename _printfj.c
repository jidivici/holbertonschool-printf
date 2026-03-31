#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

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
	count = count + write (1, &nbre, 1);
	return (count);
}
int print_int(va_list *ap)
{
	int n = 0;

	n = va_arg(*ap, int);

return (nbretotxt(n));
}
int _printf(const char *format, ...)
{
	if (format == NULL)
		return(-1);

	int i = 0, j = 0, count = 0;
	va_list ap;

	op_t print_flag[] = {
		{'i', print_int},
		{'d', print_int},
		{'\0', NULL}

	};

	va_start(ap, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			count = count + write(1,&format[i],1);
			continue;
		}
		i++;

			if (format[i] == '%')
				{
					count = count + write(1, &format[i], 1);
					continue;
				}
			if (format[i] == 'd' || format[i] == 'i')
			{
				j = 0;

				while (print_flag[j].letter != '\0')
				{
					if (format[i] == print_flag[j].letter)
					{
						count = count + print_flag[j].f(&ap);
						break;
					}
				j++;
				}

			}
			else
			{
				count = count + write(1, &format[i - 1], 1);
				count = count + write(1, &format[i], 1);
				continue;
			}
	}
	va_end(ap);
return(count);
}