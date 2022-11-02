/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:09:25 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/02 13:16:57 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_valid_width(t_ftprintf *arg_data, unsigned int n)
{
	int	n_len;
	int	precision;

	n_len = (int)ft_nbrlen(n);
	precision = arg_data->precision;
	if (arg_data->width > n_len && arg_data->width > precision)
		return (1);
	return (0);
}

static int	ft_padd_width(t_ftprintf *arg_data, unsigned int n)
{
	int	width;
	int	precision;

	precision = arg_data->precision;
	if ((int)ft_nbrlen(n) > precision)
		width = arg_data->width - (int)ft_nbrlen(n);
	else
		width = arg_data->width - precision;
	return (width);
}

int	ft_printf_unsigned_int(t_ftprintf *arg_data)
{
	unsigned int	n;

	ft_pull_precision_asterisk(arg_data);
	n = va_arg(arg_data->args, unsigned int);
	if (!arg_data->dash && !arg_data->zero && ft_valid_width(arg_data, n))
		if (0 > ft_padding(arg_data, ft_padd_width(arg_data, n), ' '))
			return (-1);
	if (!arg_data->dash && arg_data->zero && ft_valid_width(arg_data, n))
		if (0 > ft_padding(arg_data, ft_padd_width(arg_data, n), '0'))
			return (-1);
	if (arg_data->precision > (int)ft_nbrlen(n))
		if (0 > ft_check_precision(arg_data, n))
			return (-1);
	if (0 > ft_write_uint_base(arg_data, n, DEC))
		return (-1);
	if (arg_data->dash && ft_valid_width(arg_data, n))
		if (0 > ft_padding(arg_data, ft_padd_width(arg_data, n), ' '))
			return (-1);
	return (0);
}
