#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	address;
	int				count;

	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	count = 0;
	address = (unsigned long)ptr;
	count += ft_putstr("0x");
	count += ft_puthex(address, 'x');
	return (count);
}
