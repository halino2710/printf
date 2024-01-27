#include "main.h"

/**
 * print_u - Print an unsigned integer.
 * @u: Argument from va_list.
 *
 * Return: The number of characters printed.
 */
int print_u(va_list u)
{
	unsigned int num;
	char buffer[BUFFER_SIZE];
	int i, count = 0;

	num = va_arg(u, unsigned int);

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	for (i = 0; num > 0; i++)
	{
		buffer[i] = (num % 10) + '0';
		num /= 10;
	}
	for (i -= 1; i >= 0; i--)
	{
		_putchar(buffer[i]);
		count++;
	}
	return (count);
}
