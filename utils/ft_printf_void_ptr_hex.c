/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_void_ptr_hex.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:21:02 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/07 21:15:09 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int	ft_printf_void_ptr_hex(void *ptr)
{
	char	*num_str;
	int		temp_n;
	int		bytes_printed;

	bytes_printed = ft_printf_str("0x");
	if (0 > bytes_printed)
		return (bytes_printed);
	num_str = ft_unsignedtoa_base((size_t)ptr, HEX_LC);
	if (!num_str)
		return (-1);
	temp_n = ft_printf_str(num_str);
	free(num_str);
	if (0 > temp_n)
		return (-1);
	bytes_printed += temp_n;
	return (bytes_printed);
}
