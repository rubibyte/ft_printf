#include "ft_printf.h"

int	ft_printf_str(t_ftprintf *arg_data)
{
	char	*str;

	str = va_arg(arg_data->args, char *);
	if (arg_data->width > ft_strlen(str) && !arg_data->dash)
		if (0 > ft_padding(arg_data, arg_data->width - ft_strlen(str), ' '))
			return (-1);
	if (0 > ft_write_str(arg_data, str))
		return (-1);
	if (arg_data->width > ft_strlen(str) && arg_data->dash)
		if (0 > ft_padding(arg_data, arg_data->width - ft_strlen(str), ' '))
			return (-1);
	return (0);
}
