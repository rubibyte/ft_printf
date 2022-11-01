#include "ft_printf.h"

int	ft_printf_char(t_ftprintf *arg_data)
{
	char	c;
	int		temp_n;
	
	if (arg_data->percentage)
		c = '%';
	else
		c = va_arg(arg_data->args, int);
	if (arg_data->width > 1 && !arg_data->dash)
		if (0 > ft_padding(arg_data, arg_data->width - 1, ' '))
			return (-1);
	temp_n = (int)write(STDOUT_FILENO, &c, 1);
	else if (arg_data->width > 1 && arg_data->dash)
		if (0 > ft_padding(arg_data, arg_data->width - 1, ' '))
			return (-1);
	if (temp_n < 0)
		return (-1);
	arg_data->n_printed += temp_n;
	return (0);
}
