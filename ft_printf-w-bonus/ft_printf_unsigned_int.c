/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:09:25 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/03 22:07:28 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_valid_width(t_ftprintf *arg_data, unsigned int n)
{
	int	n_len;
	int	precision;

	n_len = (int)ft_nbrlen(n);
	precision = arg_data->precision;
	if (n == 0 && arg_data->dot && precision == 0)
		n_len = 0;
	return (arg_data->width > n_len && arg_data->width > precision);
}

static int	ft_padd_width(t_ftprintf *arg_data, unsigned int n)
{
	int	n_len;
	int	precision;

	n_len = (int)ft_nbrlen(n);
	precision = arg_data->precision;
	if (n == 0 && arg_data->dot && precision == 0)
		n_len = 0;
	if (precision > n_len)
		n_len = precision;
	return (arg_data->width - n_len);
}

static int	ft_check_unsigned_int(t_ftprintf *arg_data, unsigned int n)
{
	if (n == 0 && arg_data->dot && arg_data->precision == 0)
	{
		if (0 > ft_write_str(arg_data, ""))
			return (-1);
	}
	else
	{
		if (0 > ft_write_uint_base(arg_data, n, DEC))
			return (-1);
	}
	return (0);
}

int	ft_printf_unsigned_int(t_ftprintf *arg_data)
{
	unsigned int	n;

	ft_pull_precision_asterisk(arg_data);
	if (arg_data->zero && arg_data->dot)
		arg_data->zero = 0;
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
	if (0 > ft_check_unsigned_int(arg_data, n))
		return (-1);
	if (arg_data->dash && ft_valid_width(arg_data, n))
		if (0 > ft_padding(arg_data, ft_padd_width(arg_data, n), ' '))
			return (-1);
	return (0);
}
