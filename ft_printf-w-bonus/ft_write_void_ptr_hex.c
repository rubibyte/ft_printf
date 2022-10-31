/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_void_ptr_hex.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:21:02 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/10/20 18:17:53 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_void_ptr_hex(t_ftprintf arg_data, void *ptr)
{
	char		*num_str;
	int		n_wr;
	int		temp_n;

	n_wr = ft_write_str("0x");
	if (n_wr < 0)
		return (-1);
	num_str = ft_unsignedtoa_base((size_t)ptr, HEX_LC);
	if (!num_str)
		return (-1);
	temp_n = ft_write_str(num_str);
	free(num_str);
	if (temp_n < 0)
		return (temp_n);
	arg_data->n_printed += n_wr + temp_n;
	return (0);
}
