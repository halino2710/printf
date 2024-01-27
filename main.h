#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

#define BUFFER_SIZE 1024

/**
 * struct op - Struct op
 *
 * @type: The data type
 * @f: The function associated
 */
typedef struct op
{
	char *type;
	int (*f)(va_list);
} print_f;

int _putchar(char c);
void printInteger(int num);
int _printf(const char *format, ...);
int print_string(va_list s);
int print_char(va_list c);
int print_int(va_list i);
int print_dec(va_list d);
int print_bin(va_list b);
int print_oct(va_list o);
int print_u(va_list u);
int print_rev(va_list r);
int print_octal(va_list o);
int print_x(va_list x);
int print_X(va_list X);
int print_ptr(va_list p);
int print_hex(unsigned int n, unsigned int c);
int print_decimalToHexCode(unsigned long num);
int compareCharacter(char str);
int (*printf_func(const char *format))(va_list);
int print_S(va_list S);
int print_hex_value(unsigned char c);
int print_rot13(va_list R);

#endif
