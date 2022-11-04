/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_int_hex.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:08:59 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/04 15:38:39 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_valid_width(t_ftprintf *arg_data, unsigned int n)
{
	int	n_len;
	int	precision;

	n_len = (int)ft_unsignedlen_base(n, HEX_LC);
	precision = arg_data->precision;
	if (!n && arg_data->dot && !precision)
		n_len = 0;
	if (arg_data->sharp && n)
	{
		n_len += 2;
		precision += 2;
	}
	return (arg_data->width > n_len && arg_data->width > precision);
}

static int	ft_padd_width(t_ftprintf *arg_data, unsigned int n)
{
	int	n_len;
	int	precision;

	n_len = (int)ft_unsignedlen_base(n, HEX_LC);
	precision = arg_data->precision;
	if (!n && arg_data->dot && !precision)
		n_len = 0;
	if (arg_data->sharp && n)
	{
		n_len += 2;
		precision += 2;
	}
	if (precision > n_len)
		n_len = precision;
	return (arg_data->width - n_len);
}

static int	ft_check_sharp(t_ftprintf *arg_data, const char fmt, unsigned int n)
{
	if (arg_data->sharp && n)
	{
		if (fmt == 'x')
		{
			if (0 > ft_write_str(arg_data, "0x"))
				return (-1);
		}
		else
		{
			if (0 > ft_write_str(arg_data, "0X"))
				return (-1);
		}
	}
	return (0);
}

static int	ft_check_case(t_ftprintf *arg_data, const char fmt, unsigned int n)
{
	if (!n && arg_data->dot && !arg_data->precision)
	{
		if (0 > ft_write_str(arg_data, ""))
			return (-1);
	}
	else
	{
		if (fmt == 'x')
			if (0 > ft_write_uint_base(arg_data, n, HEX_LC))
				return (-1);
		if (fmt == 'X')
			if (0 > ft_write_uint_base(arg_data, n, HEX_UC))
				return (-1);
	}
	return (0);
}

int	ft_printf_unsigned_int_hex(t_ftprintf *arg_data, const char fmt)
{
	unsigned int	n;

	ft_pull_precision_asterisk(arg_data);
	if (arg_data->zero && arg_data->dot)
		arg_data->zero = 0;
	n = va_arg(arg_data->args, unsigned int);
	if (!arg_data->dash && !arg_data->zero && ft_valid_width(arg_data, n))
		if (0 > ft_padding(arg_data, ft_padd_width(arg_data, n), ' '))
			return (-1);
	if (0 > ft_check_sharp(arg_data, fmt, n))
		return (-1);
	if (!arg_data->dash && arg_data->zero && ft_valid_width(arg_data, n))
		if (0 > ft_padding(arg_data, ft_padd_width(arg_data, n), '0'))
			return (-1);
	if (0 > ft_check_precision_base(arg_data, n))
		return (-1);
	if (0 > ft_check_case(arg_data, fmt, n))
		return (-1);
	if (arg_data->dash && ft_valid_width(arg_data, n))
		if (0 > ft_padding(arg_data, ft_padd_width(arg_data, n), ' '))
			return (-1);
	return (0);
}
