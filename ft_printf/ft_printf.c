#include "ft_printf.h"
int ft_print_hex()
{

}
int ft_print_unsinged (unsigned int format, char symbol)
{
    return (-1);
}
void ft_putnbr(int n, int *len)
{

    if (n == -2147483648)
    {
        *len = write(1,"-2147483648", 11);
        return ;
    }
    else if (n < 0)
    {
        *len += write(1,"-", 1);
        n *= -1;
        ft_putnbr(n, len);
    }
    else if (n < 10)
    {
        char tmp;
        tmp = n % 10 + '0';
        *len = write(1, &tmp, 1);
    }
    else
    {
        char tmp;
        ft_putnbr(n / 10, len);
        tmp = n % 10 + '0';
        *len = write(1, &tmp, 1);
    }
}


int ft_print_number(int format)
{
    int len;

    len = 0;
    ft_putnbr(format, &len);
    return (len);
}

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

int print_symbol(va_list ap, const char **format) {
    int len;

    len = 0;
    (*format)++;
    if (**format == '%')
        len = ft_putchar(**format);
    else if (**format == 'c')
        len = ft_putchar(va_arg(ap, int));
    else if (**format == 's')
        len = ft_print_string(va_arg(ap, char*));
    else if (**format == 'p')
        printf("The void * pointer argument is printed in hexadecimal.\n");
    else if (**format == 'd' || **format == 'i')
        len = ft_print_number(va_arg(ap, int));
    else if (**format == 'u')
        len = ft_print_unsinged(va_arg(ap, unsigned int), **format);
    else if (**format == 'x' || **format == 'X')
        len = ft_print_hex(va_arg(ap, ))
        printf("print a Number in hexadecimal (base 16), with lowercase or Uppercase\n");
    else if (!**format)
        return (0);
    return len;
}

int parse_format(va_list ap, const char *format) {
    int len;

    len = 0;
    while (*format) {
        if (*format == '%') {
            print_symbol(ap, &format);
            len += 0; // print
        } else if (*format)
            len += ft_putchar(*format);
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