#include "ft_printf.h"

int	ft_there_is_flag(const char *fmt, int i)
{
	if (fmt[i] && ft_strchr("# +-0", fmt[i]))
		return (1);
	return (0);
}

int	ft_there_is_width(const char *fmt, int i)
{
	if (fmt[i] && ft_strchr("123456789", fmt[i]))
		return (1);
	return (0);
}

int	ft_there_is_precision_dot(const char *fmt, int i)
{
	if (fmt[i] == '.' && ft_strchr("0123456789", fmt[i + 1 ]))
		return (1);
	else if (fmt[i] == '.' && fmt[i + 1] == '*')
		return (1);
	return (0);
}

int	ft_there_is_precision_asterisk(const char *fmt, int i)
{
	if (fmt[i] == '.' && fmt[i + 1] == '*')
		return (1);
	return (0);
}

int	ft_there_is_type(const char *fmt, int i)
{
	if (fmt[i] && ft_strchr("cspdiuxX%", fmt[i]))
		return (1);
	return (0);
}
	
