/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:03:26 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/15 22:06:11 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils_bonus.h"

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

int	ft_check_fmt(t_ftprintf *arg_data, const char *fmt, int i)
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
			arg_data->bytes_printed += temp_n;
		}
		else
			i = ft_check_arg(arg_data, fmt, i + 1);
		if (0 > i)
		{
			free(arg_data);
			return (-1);
		}
	}
	return (0);
}
