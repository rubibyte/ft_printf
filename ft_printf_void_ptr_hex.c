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

ssize_t	ft_printf_void_ptr_hex(void *ptr)
{
	char		*num_str;
	ssize_t		n_wr;
	ssize_t		temp_n;

	n_wr = ft_printf_str("0x");
	if (n_wr < 0)
		return (n_wr);
	num_str = ft_adresstoa_base((size_t)ptr, HEX_LC);
	if (!num_str)
		return (-1);
	temp_n = ft_printf_str(num_str);
	free(num_str);
	if (temp_n < 0)
		return (temp_n);
	n_wr += temp_n;
	return (n_wr);
}
