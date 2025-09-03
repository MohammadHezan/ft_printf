#include "../ft_printf.h"

int	ft_puthex(unsigned long n, char format)
{
	char	*base;
	int		printed_chars;

	printed_chars = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
		printed_chars += ft_puthex(n / 16, format);
	printed_chars += ft_putchar(base[n % 16]);
	return (printed_chars);
}
