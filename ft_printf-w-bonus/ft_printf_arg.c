/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:40:07 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/03 19:24:49 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_arg(t_ftprintf *arg_data, const char fmt)
{
	int	ret;

	ret = 0;
	if (fmt == 'c' || fmt == '%')
		ret = ft_printf_char(arg_data);
	else if (fmt == 's')
		ret = ft_printf_str(arg_data);
	else if (fmt == 'p')
		ret = ft_printf_void_ptr_hex(arg_data);
	else if (fmt == 'd' || fmt == 'i')
		ret = ft_printf_int(arg_data);
	else if (fmt == 'u')
		ret = ft_printf_unsigned_int(arg_data);
	else if (fmt == 'x' || fmt == 'X')
		ret = ft_printf_unsigned_int_hex(arg_data, fmt);
	return (ret);
}
