/**
 * print_hex - print in base 16
 * @n: an integer
 *
 * Return: (count), number of characters printed
 */
int print_hex(unsigned int n)
{
	char *alphab = "0123456789ABCDEF";
	int count = 0;

	if(n >= 16)
		count = count + (print_hex(n / 16));
	write(1, &alphab[n % 16], 1);
	count++;
return (count);
}
int print_hex_min(unsigned int n)
{
	char *alphab = "0123456789abcdef";
	int count = 0;

	if(n >= 16)
		count = count + (print_hex(n / 16));
	write(1, &alphab[n % 16], 1);
	count++;
return (count);
}
