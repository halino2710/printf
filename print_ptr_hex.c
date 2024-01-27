#include <stdarg.h>
#include "main.h"

/**
 * print_decimalToHexCode - prints hexcode of a decimal value
 * @num: number to be converted
 *
 * Return: number of characters printed
 */
int print_decimalToHexCode(unsigned long num)
{
	int count = 0, i = 0;
	char hex_buffer[32];
	char hex_chars[] = "0123456789abcdef";

	if (num == 0)
	{
		_putchar('0');
		count++;
	}
	else
	{
		while (num > 0)
		{
			hex_buffer[i] = hex_chars[num % 16];
			num /= 16;
			i++;
		}

		for (--i; i >= 0; i--)
		{
			_putchar(hex_buffer[i]);
			count++;
		}
	}
	return (count);
}

/**
 * print_hex_value - Print the hexadecimal representation of a character.
 * @c: The character for which to print the hexadecimal value.
 *
 * Return: The number of characters printed (always 2).
 */
int print_hex_value(unsigned char c)
{
	int count = 0;
	int value = c;
	int upper_digit = value / 16;
	int lower_digit = value % 16;

	_putchar("0123456789ABCDEF"[upper_digit]);
	_putchar("0123456789ABCDEF"[lower_digit]);

	count += 2;

	return (count);
}
