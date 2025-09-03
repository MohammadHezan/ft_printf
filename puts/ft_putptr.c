#include "../ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	address;
	int				printed_chars;

	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	printed_chars = 0;
	address = (unsigned long)ptr;
	printed_chars += ft_putstr("0x");
	printed_chars += ft_puthex(address, 'x');
	return (printed_chars);
}
