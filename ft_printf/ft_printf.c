#include <stdarg.h>
#include <unistd.h>

void	printstr(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
		*len += write(1, str++, 1);
}

void	printdigit(long long int i, int base, int *len)
{
	char *hexa;

	if (i < 0)
	{
		i *= -1;
		*len += write(1, "-", 1);
	}
	if (i >= base)
		printdigit((i / base), base, len);
	hexa = "0123456789abcdef";
	*len += write(1, &hexa[i % base], 1);
}

int	ft_printf(const char *format, ... )
{
	int	len;
	va_list	arg;

	len = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
				printstr(va_arg(arg, char *), &len);
			else if (*format == 'd')
				printdigit((long long int)va_arg(arg, int), 10, &len);
			else if (*format == 'x')
				printdigit((long long int)va_arg(arg, unsigned int), 16, &len);
		}
		else
			len += write(1, format, 1);
		format++;
	}
	va_end(arg);
	return (len);
}
