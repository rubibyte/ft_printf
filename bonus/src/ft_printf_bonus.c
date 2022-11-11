/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 23:19:35 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/11 19:42:24 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils_bonus.h"

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
