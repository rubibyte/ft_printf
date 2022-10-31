#include "ft_printf.h"

static int	ft_padding(t_ftprintf arg_data, int n, char p)
{
	int	i;
	int	temp_n;

	i = -1;
	while (++i < n)
	{
		temp_n = (int)write(STDOUT_FILENO, &p, 1);
		if (temp_n < 0)
			return (temp_n);
		arg_data->n_printed += temp_n;
	}
	return (0);
}

static int	ft_printf_char(t_ftprintf arg_data)
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

static int	ft_printf_str(t_ftprintf arg_data)
{
	char	*str;

	str = va_arg(arg_data->args, char *);
	if (arg_data->width > ft_strlen(str) && !arg_data->dash)
		if (0 > ft_padding(arg_data, arg_data->width - ft_strlen(str), ' '))
			return (-1);
	if (0 > ft_printf_str(arg_data, str))
		return (-1);
	if (arg_data->width > ft_strlen(str) && arg_data->dash)
		if (0 > ft_padding(arg_data, arg_data->width - ft_strlen(str), ' '))
			return (-1);
	return (0);
}

















int	ft_printf_arg(t_ftprintf arg_data, const char fmt)
{
	int	temp_n;

	if (fmt == 'c' || fmt == '%')
		temp_n = ft_printf_char(arg_data);
	else if (fmt == 's')
		temp_n = ft_printf_str(arg_data);
	else if (fmt == 'p')
		temp_n = ft_printf_void_ptr_hex(arg_data)
		
			
	si todo bien retorna 0;
	si error retorna -1;


	ft_reset_arg_data
