/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 23:19:35 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/07 20:02:11 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_ftprintf	*ft_init_arg_data(t_ftprintf *arg_data)
{
	arg_data->sharp = 0;
	arg_data->zero = 0;
	arg_data->dash = 0;
	arg_data->space = 0;
	arg_data->sign = 0;
	arg_data->width = 0;
	arg_data->dot = 0;
	arg_data->asterisk = 0;
	arg_data->precision = 0;
	arg_data->percentage = 0;
	arg_data->n_printed = 0;
	return (arg_data);
}

static void	ft_reset_arg_data(t_ftprintf *arg_data)
{
	arg_data->sharp = 0;
	arg_data->zero = 0;
	arg_data->dash = 0;
	arg_data->space = 0;
	arg_data->sign = 0;
	arg_data->width = 0;
	arg_data->dot = 0;
	arg_data->asterisk = 0;
	arg_data->precision = 0;
	arg_data->percentage = 0;
}

static int	ft_check_arg(t_ftprintf *arg_data, const char *fmt, int i)
{
	if (!ft_check_valid_format(fmt, i))
		return (i--);
	i = ft_fetch_arg_data(arg_data, fmt, i);
	if (0 > ft_printf_arg(arg_data, fmt[i]))
		return (-1);
	ft_reset_arg_data(arg_data);
	return (i);
}

static int	ft_check_fmt(t_ftprintf *arg_data, const char *fmt, int i)
{
	int	temp_n;

	while (fmt[++i])
	{
		if (fmt[i] != '%')
		{
			temp_n = (int)write(STDOUT_FILENO, &fmt[i], 1);
			if (0 > temp_n)
			{
				va_end(arg_data->args);
				free(arg_data);
				return (-1);
			}
			arg_data->n_printed += temp_n;
		}
		if (fmt[i] == '%')
			i = ft_check_arg(arg_data, fmt, i + 1);
		if (0 > i)
		{
			free(arg_data);
			return (-1);
		}
	}
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	int			bytes_printed;
	t_ftprintf	*arg_data;

	arg_data = (t_ftprintf *)malloc(sizeof(t_ftprintf));
	if (!arg_data)
		return (-1);
	arg_data = ft_init_arg_data(arg_data);
	va_start(arg_data->args, fmt);
	if (0 > ft_check_fmt(arg_data, fmt, -1))
		return (-1);
	va_end(arg_data->args);
	bytes_printed = arg_data->n_printed;
	free(arg_data);
	return (bytes_printed);
}
