/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_void_ptr_hex.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:21:02 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/10/18 18:39:08 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_void_ptr_hex(void *ptr)
{
	int		n_wr;
	char	*num_str;
	int		temp_n;

	n_wr = (int)write(1, "0x", 2);
	if (n_wr < 0)
		return (n_wr);
	num_str = ft_lgtoa_base((size_t)ptr, "0123456789abcdef");
	//temp_n = (int)write(1, num_str, ft_strlen(num_str));
	temp_n = ft_printf_str(num_str);
	if (temp_n < 0)
		return (temp_n);
	free(num_str);
	num_str = NULL;
	n_wr += temp_n;
	return (n_wr);
}
