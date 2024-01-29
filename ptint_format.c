#include <stdio.h>
#include <stdarg.h>

void _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%') {
            format++;
            
            // Check for the width specifier
            int width = 0;
            while (*format >= '0' && *format <= '9') {
                width = width * 10 + (*format - '0');
                format++;
            }

            // Process the conversion specifier
            switch (*format) {
                case 'c': {
                    int c = va_arg(args, int);
                    putchar(c);
                    break;
                }
                case 's': {
                    char *str = va_arg(args, char *);
                    for (int i = 0; i < width && *str != '\0'; i++, str++) {
                        putchar(*str);
                    }
                    break;
                }
                case 'd':
                case 'i': {
                    int num = va_arg(args, int);
                    printf("%*d", width, num);
                    break;
                }
                default:
                    putchar('%');
                    if (width > 0) {
                        printf("%*c", width - 1, *format);
                    } else {
                        putchar(*format);
                    }
            }
        } else {
            putchar(*format);
        }
        format++;
    }

    va_end(args);
}

int main(void) {
    _printf("This is a test: %5s, %10d, %c, %s\n", "Hello", 42, 'A', "World");
    _printf("Hello, %10c World! %s %%\n", 'H', "Happy");

    return 0;
}

