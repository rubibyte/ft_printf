/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_void_ptr_hex_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:09:50 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/11 19:42:56 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils_bonus.h"

int	ft_printf_void_ptr_hex(t_ftprintf *arg_data)
{
	void	*ptr;
	int		ptr_len;

	ptr = va_arg(arg_data->args, void *);
	ptr_len = (int)ft_unsignedlen_base((size_t)ptr, HEX_LC) + 2;
	if (arg_data->width > ptr_len && !arg_data->dash)
		if (0 > ft_padding(arg_data, arg_data->width - ptr_len, ' '))
			return (-1);
	if (0 > ft_write_void_ptr_hex(arg_data, ptr))
		return (-1);
	if (arg_data->width > ptr_len && arg_data->dash)
		if (0 > ft_padding(arg_data, arg_data->width - ptr_len, ' '))
			return (-1);
	return (0);
}
