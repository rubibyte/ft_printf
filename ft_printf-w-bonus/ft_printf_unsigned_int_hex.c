/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_int_hex.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:08:59 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/01 20:54:09 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf_unsigned_int_hex(t_ftprintf *arg_data, const char fmt)
{
	unsigned int	n;

	ft_pull_precision_asterisk(arg_data);
	n = va_arg(arg_data->args, unsigned int);
	if (arg_data->width > (int)ft_unsignedlen_base(n, HEX_LC) && arg_data->width > arg_data->precision && !arg_data->dash && !arg_data->zero)
		if (0 > ft_padding(arg_data, arg_data->width - (int)ft_unsignedlen_base(n, HEX_LC), ' '))
			return (-1);
	if (arg_data->sharp && n > 0)
	{
		if (fmt == 'x')
		{
			if (0 > ft_write_str(arg_data, "0x"))
				return (-1);
		}
		else
		{
			if (0 > ft_write_str(arg_data, "0x"))
				return (-1);
		}
	}
	if (arg_data->width > (int)ft_unsignedlen_base(n, HEX_LC) && !arg_data->precision && arg_data->zero && !arg_data->dash)
		if (0 > ft_padding(arg_data, arg_data->width - (int)ft_unsignedlen_base(n, HEX_LC), '0'))
			return (-1);
	ft_check_precision_base(arg_data, n);
	if (fmt == 'x')
		if (0 > ft_write_uint_base(arg_data, n, HEX_LC))
			return (-1);
	if (fmt == 'X')
		if (0 > ft_write_uint_base(arg_data, n, HEX_UC))
			return (-1);
	if (arg_data->width > (int)ft_unsignedlen_base(n, HEX_LC) && arg_data->width > arg_data->precision && arg_data->dash)
		if (0 > ft_padding(arg_data, arg_data->width - ft_unsignedlen_base(n, HEX_LC), ' '))
			return (-1);
	return (0);
}
