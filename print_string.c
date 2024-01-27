#include "main.h"
#include <stdlib.h>
/**
 * print_string - writes the character c to stdout
 * @s: The string to print
 *
 * Return: i
 */
int print_string(va_list s)
{
	char *my_string;
	int i = 0, count = 0;

	my_string = va_arg(s, char *);
	if (my_string == NULL)
	{
		my_string = "(null)";
	}
	for (; my_string[i] != '\0'; i++)
	{
		_putchar(my_string[i]);
		count++;
	}
	return (count);
}
