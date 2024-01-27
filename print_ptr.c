#include "main.h"

/**
 * print_ptr - Prints a pointer's address in hexadecimal format.
 * @p: Argument from va_list
 *
 * Return: The number of characters printed.
 */
int print_ptr(va_list p)
{
	int count = 0, i = 0;
	unsigned long num;
	void *ptr = va_arg(p, void *);
	char *str_null = "(nil)";

	/* check if ptr is not null */
	if (ptr == NULL)
	{
		for (; str_null[i] != '\0'; i++)
		{
			_putchar(str_null[i]);
			count++;
		}

		return (count);
	}

	_putchar('0');
	_putchar('x');
	count += 2;

	/* convert and print the pointer in hexadecimal. */
	num = (unsigned long)ptr;
	count += print_decimalToHexCode(num);

	return (count);
}
