/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_void_ptr_hex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:21:02 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/16 21:31:25 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int	ft_write_void_ptr_hex(t_ftprintf *arg_data, void *ptr)
{
	char	*num_str;

	if (0 > ft_write_str(arg_data, "0x"))
		return (-1);
	num_str = ft_unsignedtoa_base((size_t)ptr, HEX_LC);
	if (!num_str)
		return (-1);
	if (0 > ft_write_str(arg_data, num_str))
	{
		free(num_str);
		return (-1);
	}
	free(num_str);
	return (0);
}
