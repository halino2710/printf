#include "main.h"
#include <stdarg.h>

/**
 * print_oct - Converts an integer to octal
 * @o: Argument from va_list
 *
 * Return: the number of characters printed
 */
int print_oct(va_list o)
{
	unsigned int num;
	int i, count = 0;
	int octal[BUFFER_SIZE];

	num = va_arg(o, unsigned int);
	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	for (i = 0; num > 0; i++)
	{
		octal[i] = num % 8;
		num /= 8;
	}
	for (i -= 1; i >= 0; i--)
	{
		_putchar(octal[i] + '0');
		count++;
	}
	return (count);
}
