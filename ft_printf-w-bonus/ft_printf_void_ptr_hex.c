#include "ft_printf.h"

int	ft_printf_void_ptr_hex(t_ftprintf *arg_data)
{
	void	*ptr;

	ptr = va_arg(arg_data->args, void *);
	if (arg_data->width > (int)ft_unsignedlen_base((size_t)ptr, HEX_LC) && !arg_data->dash)
		if (0 > ft_padding(arg_data, arg_data->width - (int)ft_unsignedlen_base((size_t)ptr, HEX_LC), ' '))
			return (-1);
	if (0 > ft_write_void_ptr_hex(arg_data, ptr))
		return (-1);
	if (arg_data->width > (int)ft_unsignedlen_base((size_t)ptr, HEX_LC) && arg_data->dash)
		if (0 > ft_padding(arg_data, arg_data->width - (int)ft_unsignedlen_base((size_t)ptr, HEX_LC), ' '))
			return (-1);
	return (0);
}
