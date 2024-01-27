#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * printf_func - function that finds format for _printf
 *		and calls the correct function.
 * @format: type of data(int, char, string, decimal etc)
 *
 * Return: NULL or function that corresponds to the given format
 */
int (*printf_func(const char *format))(va_list)
{
	unsigned int i = 0;
	print_f form[] = {
		{"c", print_char},
		{"s", print_string},
		{"S", print_S},
		{"d", print_dec},
		{"i", print_int},
		{"b", print_bin},
		{"r", print_rev},
		{"o", print_oct},
		{"x", print_x},
		{"X", print_X},
		{"u", print_u},
		{"p", print_ptr},
		{"R", print_rot13},
		{NULL, NULL}
	};

	while (form[i].type)
	{
		if (form[i].type[0] == (*format))
		{
			return (form[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * _printf - Prints output according to format
 * @format: type of data(int, char, string, decimal etc)
 *
 * Return: size or number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list input;
	int (*f)(va_list);
	unsigned int i = 0, count = 0;

	if (format == NULL)
		return (-1);
	va_start(input, format);
	while (format[i])
	{
		while (format[i] != '%' && format[i])
		{
			_putchar(format[i]);
			count++;
			i++;
		}
		if (format[i] == '\0')
			return (count);
		f = printf_func(&format[i + 1]);
		if (f != NULL)
		{
			count += f(input);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		count++;
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	va_end(input);
	return (count);
}
