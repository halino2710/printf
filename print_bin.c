#include "main.h"

/**
 * print_bin - converts number to binary
 * @b: unsigned int argument to be converted to binary
 *
 * Return: number of chars printed
 */
int print_bin(va_list b)
{
	unsigned int n;
	int i, count = 0;
	int binary[BUFFER_SIZE];

	n = va_arg(b, unsigned int);
	if (n == 0)
	{
		_putchar('0');
		return (1);
	}
	for (i = 0; n > 0; i++)
	{
		binary[i] = n % 2;
		n /= 2;
	}
	for (i -= 1; i >= 0; i--)
	{
		_putchar(binary[i] + '0');
		count++;
	}
	return (count);
}
