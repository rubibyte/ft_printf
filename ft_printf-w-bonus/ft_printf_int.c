#include "ft_printf.h"

int	ft_printf_int(t_ftprintf *arg_data)
{
	int	n;
	//tener en cuenta el signo en width, width > precision+signo, e.g. precision + ft_is_signed(arg_data, n)
	//ft_expected_width vs
	//poner en las otras funciones
	//poner las condiciones de los if en orden de restrictivas
	ft_pull_precision_asterisk(arg_data);
	n = va_arg(arg_data->args, int);
	if ((arg_data->width > (int)ft_nbrlen(n) && arg_data->width > arg_data->precision)&& !arg_data->dash && !arg_data->zero)
		if (0 > ft_padding(arg_data, arg_data->width - (int)ft_nbrlen(n), ' '))
			return (-1);
	if (arg_data->sign && n > -1)
		if (0 > ft_write_str(arg_data, "+"))
			return (-1);
	else if (arg_data->space && !arg_data->sign)
		if (0 > ft_write_str(arg_data, " "))
			return (-1);
	if (n < 0)
		if (0 > ft_write_str(arg_data, "-"))
			return (-1);
	if ((arg_data->width > (int)ft_nbrlen(n) && arg_data->zero && !arg_data->dash && !arg_data->precision)
		if (0 > ft_padding(arg_data, arg_data->width - (int)ft_nbrlen(n), '0'))
			return (-1);
	if (arg_data->precision > ft_nbrlen(ft_absval(n)))
		if (0 > ft_check_precision_int(arg_data, ft_absval(n)))
			return (-1);
	if (0 > ft_write_int(arg_data, ft_absval(n)))
			return (-1);
	if ((arg_data->width > (int)ft_nbrlen(n) && arg_data->width > arg_data->precision) && arg_data->dash)
		if (0 > ft_padding(arg_data, arg_data->width - (int)ft_nbrlen(n), ' '))
			return (-1);
	return (0);
}
