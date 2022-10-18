/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_void_ptr_hex.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:21:02 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/10/17 20:24:42 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	ft_printf_void_ptr_hex(void *ptr)
{
	//size_t	address;
	int		n_char_wr;
	char	*num_str;
	int		temp_n;

	//address = (size_t)ptr;
	n_char_wr = (int)write(1, "0x", 2);
	if (n_char_wr < 0)
		return (n_char_wr);
	//n_char_wr = ft_printf_hex_long((size_t)ptr);
	num_str = ft_lgtoa_base((size_t)ptr, "0123456789abcdef");
	temp_n = (int)write(1, num_str, ft_strlen(num_str));
	if (temp_n < 0)
		return (temp_n);
	free(num_str);
	num_str = NULL;
	n_char_wr += temp_n;
	return (n_char_wr);
}
