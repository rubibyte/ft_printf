#include "ft_printf.h"

int	ft_printf_unsigned_int(t_ftprintf *arg_data)
{
	unsigned int	n;

	ft_pull_precision_asterisk(arg_data);
	n = va_arg(arg_data->args, unsigned int);
	if (arg_data->width > (int)ft_nbrlen(n) && !arg_data->dash && !arg_data->zero)
		if (0 > ft_padding(arg_data, arg_data->width - (int)ft_nbrlen(n), ' '))
			return (-1);
	else if (arg_data->width > (int)ft_nbrlen(n) && arg_data->zero && !arg_data->dash && !arg_data->precision)
		if (0 > ft_padding(arg_data, arg_data->width - (int)ft_nbrlen(n), '0'))
			return (-1);
	if (arg_data->precision > ft_nbrlen(n))
		if (0 > ft_check_precision(arg_data, n))
			return (-1);
	if (0 > ft_write_uint_base(arg_data, n, DEC))
		return (-1);
	if (arg_data->width > (int)ft_nbrlen(n) && arg_data->dash)
		if (0 > ft_padding(arg_data, arg_data->width - (int)ft_nbrlen(n), ' '))
			return (-1);
	return (0);
}
