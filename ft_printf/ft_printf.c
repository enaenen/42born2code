#include "ft_printf.h"

int ft_print_string(char *str)
{
    int len;
    len = 0;

    if (!str)
        len = ft_putstr("(null)");
    else
        len = ft_putstr(str);
    return (len);
}

int ft_print_pointer(unsigned long long p)
{
    int len;
    char *pointer;

    if (!p)
    {
        len = ft_putstr("0x0");
        return len;
    }
    pointer = ft_putnbr_hexbase(p);
    if (!pointer)
        return (0);
    len = ft_putstr("0x");
    len += ft_putstr(pointer);
    free(pointer);
    return len;
}

int print_symbol(va_list ap, const char **format)
{
    int len;

    len = 0;
    (*format)++;
    if (**format == '%')
        len = ft_putchar(**format);
    else if (**format == 'c')
        len = ft_putchar(va_arg(ap, int));
    else if (**format == 's')
        len = ft_print_string(va_arg(ap,char*));
    else if (**format == 'p')
        len = ft_print_pointer(va_arg(ap, unsigned long long));
    else if (**format == 'd' || **format == 'i')
        len = ft_print_number(va_arg(ap, int));
    else if (**format == 'u' || **format == 'x' || **format == 'X')
        len = ft_print_unsigned(va_arg(ap,unsigned int), **format);
    else if (!**format)
        return (0);
    return len;
}

int parse_format(va_list ap, const char *format)
{
    int len;

    len = 0;
    while (*format)
    {
        if (*format == '%')
            len += print_symbol(ap, &format);
        else if (*format)
            len += ft_putchar(*format);
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