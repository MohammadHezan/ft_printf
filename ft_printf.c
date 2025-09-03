#include "ft_printf.h"

int	handle_format(char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 'x'));
	else if (format == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 'X'));
	else if (format == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		printed_chars;
	int		i;
	va_list	args;

	if (!format)
		return (0);
	printed_chars = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			printed_chars += handle_format(format[i], args);
		}
		else
		{
			write(1, &format[i], 1);
			printed_chars++;
		}
		i++;
	}
	return (printed_chars);
}
