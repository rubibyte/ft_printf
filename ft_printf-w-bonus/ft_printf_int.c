/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:08:01 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/02 13:00:48 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_valid_width(t_ftprintf *arg_data, int n)
{
	int	n_len;
	int	precision;

	n_len = (int)ft_nbrlen(n);
	if (n < 0 || arg_data->sign)
		precision = arg_data->precision + 1;
	else 
		precision = arg_data->precision;
	if (arg_data->width > n_len && arg_data->width > precision)
		return (1);
	return (0);
}

static int	ft_padd_width(t_ftprintf *arg_data, int n)
{
	int	width;
	int	precision;

	if (n < 0 || arg_data->sign)
		precision = arg_data->precision + 1;
	else
		precision = arg_data->precision;
	if ((int)ft_nbrlen(n) > precision)
		width = arg_data->width - (int)ft_nbrlen(n);
	else
		width = arg_data->width - precision;
	return (width);
}

int	ft_printf_int(t_ftprintf *arg_data)
{
	int	n;
	//tener en cuenta el signo en width, width > precision+signo, e.g. precision + ft_is_signed(arg_data, n)
	//ft_expected_width vs
	//poner en las otras funciones
	//poner las condiciones de los if en orden de restrictivas
	ft_pull_precision_asterisk(arg_data);
	n = va_arg(arg_data->args, int);
	if (!arg_data->dash && !arg_data->zero && ft_valid_width(arg_data, n))
		if (0 > ft_padding(arg_data, ft_padd_width(arg_data, n), ' '))
			return (-1);
	if (arg_data->sign && n > -1)
		if (0 > ft_write_str(arg_data, "+"))
			return (-1);
	if (!arg_data->sign && arg_data->space)
		if (0 > ft_write_str(arg_data, " "))
			return (-1);
	if (n < 0)
		if (0 > ft_write_str(arg_data, "-"))
			return (-1);
	if (!arg_data->dash && !arg_data->zero && ft_valid_width(arg_data, n))
		if (0 > ft_padding(arg_data, ft_padd_width(arg_data, n), '0'))
			return (-1);
	if (arg_data->precision > (int)ft_nbrlen(ft_absval(n)))
		if (0 > ft_check_precision(arg_data, ft_absval(n)))
			return (-1);
	if (0 > ft_write_int(arg_data, ft_absval(n)))
			return (-1);
	if (ft_valid_width(arg_data, n) && arg_data->dash)
		if (0 > ft_padding(arg_data, ft_padd_width(arg_data, n), ' '))
			return (-1);
	return (0);
}
