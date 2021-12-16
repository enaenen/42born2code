#include "ft_printf.h"

int print_symbol(va_list ap, const char **format) {
    int len;

    len = 0;
    ap=NULL;

    (*format)++;
    if (**format == '%')
        len = putchar(**format);
    else if (**format == 'c')
        printf("print a single character\n");
    else if (**format == 's')
        printf("print a string of characters\n");
    else if (**format == 'p')
        printf("The void * pointer argument is printed in hexadecimal.\n");
    else if (**format == 'd')
        printf("print a decimal number(base 10)\n");
    else if (**format == 'i')
        printf("print an integer in base 10\n");
    else if (**format == 'u')
        printf("print an unsigned decimal (Base 10) number\n");
    else if (**format == 'x' || **format == 'X')
        printf("print a Number in hexadecimal (base 16), with lowercase or Uppercase\n");

    return len;
}

int parse_format(va_list ap, const char *format) {
    int len;

    len = 0;
    while (*format) {
        if (*format == '%')
        {
            print_symbol(ap, &format);
            len += 0; // print
        }
        else if (*format)
            len += putchar(*format);
        if (*format)
            format++;
    }
    return (len);
}

int ft_printf(const char *format, ...) {
    va_list ap;
    int len;

    va_start(ap, format);
    len = parse_format(ap, format);
    va_end(ap);
    return (len);
}
