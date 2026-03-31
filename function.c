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
	count = count + write(1, &nbre, 1);
	return (count);
}
int print_int(va_list *ap)
{
	int n = 0;

	n = va_arg(*ap, int);

return (nbretotxt(n));
}
