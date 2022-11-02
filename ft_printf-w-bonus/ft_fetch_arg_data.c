#include "ft_printf.h"

static int	ft_fetch_flags(t_ftprintf *arg_data, const char *fmt, int i)
{
	while (fmt[i] && ft_strchr("# +-0", fmt[i]))
	{
		if (fmt[i] == '#')
			arg_data->sharp = 1;
		else if (fmt[i] == ' ')
			arg_data->space = 1;
		else if (fmt[i] == '+')
			arg_data->sign = 1;
		else if (fmt[i] == '-')
			arg_data->dash = 1;
		else
			arg_data->zero = 1;
		i++;
	}
	return (i);
}

static int ft_fetch_width(t_ftprintf *arg_data, const char *fmt, int i)
{
	int	width;

	width = 0;
	while (fmt[i] && ft_strchr("0123456789", fmt[i]))
	{
		width = width * 10 + (fmt[i] - '0');
		i++;
	}
	arg_data->width = width;
	return (i);
}

static int	ft_fetch_precision(t_ftprintf *arg_data, const char *fmt, int i)
{
	int	precision;

	if (fmt[i + 1] == '*')
		arg_data->asterisk = 1;
	else
	{
		precision = 0;
		while (fmt[i] && ft_strchr("0123456789", fmt[i]))
		{
			precision = precision * 10 + (fmt[i] - '0');
			i++;
		}
		arg_data->dot = 1;
		arg_data->precision = precision;
	}
	return (i);
}

/*static int	ft_fetch_precis_astrsk(t_ftprintf *arg_data, const char *fmt, int i)
{
	if (fmt[++i] == '*')
		arg_data->asterisk = 1;
	return (i--);
}*/

static int	ft_fetch_percentage(t_ftprintf *arg_data, const char *fmt, int i)
{
	if (fmt[i] == '%')
		arg_data->percentage = 1;
	return (i);
}

int	ft_fetch_arg_data(t_ftprintf *arg_data, const char *fmt, int i)
{
	i = ft_fetch_flags(arg_data, fmt, i);
	i = ft_fetch_width(arg_data, fmt, i);
	i = ft_fetch_precision(arg_data, fmt, i);
	i = ft_fetch_percentage(arg_data, fmt, i);

	return (i);
}


