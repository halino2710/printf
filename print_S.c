#include <stdarg.h>
#include "main.h"

/**
 * print_S - prints the string
 * Non printable characters (0 < ASCII value < 32 or >= 127) are
 * printed this way:
 * \x, followed by the ASCII code value in hexadecimal
 * (upper case - always 2 characters)
 * @S: string to convert
 *
 * Return: the number of characters printed
 */
int print_S(va_list S)
{
	char *str = va_arg(S, char *);
	int count = 0;

	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		if (*str < 32 || *str >= 127)
		{
			_putchar('\\');
			_putchar('x');
			count += 2;
			count += print_hex_value(*str);
		}
		else
		{
			_putchar(*str);
			count++;
		}
		str++;
	}
	return (count);
}
