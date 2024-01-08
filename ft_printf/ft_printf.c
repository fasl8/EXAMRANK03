#include <stdarg.h>
#include <unistd.h>

void ft_putstr(char *str, int *len)
{
    if(!str)
        str = "(null)";
    while(*str)
        *len += write(1, str++, 1);
}

void ft_putnbr(long long int i, int base, int *len)
{
    if(i < 0)
    {
        i *= -1;
        *len += write(1, "-", 1);
    }
    if(i >= base)
        ft_putnbr((i / base), base, len);
    char *hexa = "0123456789abcdef";
    *len += write(1, &hexa[i % base], 1);
}

int ft_printf(const char *str, ...)
{
    int len = 0;
    va_list arg;
    va_start(arg, str);
    while(*str)
    {
        if(*str == '%')
        {
            str++;
            if(*str == 's')
                ft_putstr(va_arg(arg, char *), &len);
            else if(*str == 'd')
                ft_putnbr((long long int)va_arg(arg, int), 10, &len);
            else if(*str == 'x')
                ft_putnbr((long long int)va_arg(arg, unsigned int), 16, &len);
        }
        else
            len += write(1, str, 1);
        str++;
    }
    return(va_end(arg), len);
}