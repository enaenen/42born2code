#include "ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int print_symbol(va_list ap, const char **format) {
    int len;

    len = 0;
    (*format)++;
    if (**format == '%')
        len = putchar(**format);
    else if (**format == 'd')
        printf("this is Int");
    else if (**format == 'c')
        printf("this is char");

    else if (**format == 's')
        printf("this is String");

    else if (**format == 'p')
        printf("this is Int");

    else if (**format == 'i')
    else if (**format == 'u' || **format == 'x' || **format =='X')
}

int parse_format(va_list ap, const char *format)
{
    int len;

    len = 0;
    while (*format)
    {
        if (*format == '%')
            rt += 0; // print
        else if (*format)
            len += putchar(*format);
        if (*format)
            format++;
    }
    return (len);
}

int ft_printf(const char *format, ...)
{
    va_list ap;
    int len;

    va_start(ap, format);
    len = parse_format(ap, format);
    va_end(ap);
    return (len);
}