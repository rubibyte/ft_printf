/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_void_ptr_hex.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:21:02 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/10/13 00:25:15 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static int	ft_printf_hex_long(size_t n)
{
	char	*hex_low;
	char	c;
	int		n_char_wr;

	hex_low = ft_strdup("0123456789abcdef");
	if (n <= 16)
	{
		c = hex_low[n];
		n_char_wr = (int)write(1, &c, 1);
		free(hex_low);
		if (n_char_wr < 0)
			return (n_char_wr);
	}
	else
	{
		ft_printf_hex_long(n / 16);
		ft_printf_hex_long(n % 16);
	}
	return (0);
}

int	ft_printf_void_ptr_hex(void *ptr)
{
	//size_t	address;
	int	n_char_wr;

	//address = (size_t)ptr;
	n_char_wr = (int)write(1, "0x", 2);
	if (n_char_wr < 0)
		return (n_char_wr);
	n_char_wr = ft_printf_hex_long((size_t)ptr);
	if (n_char_wr < 0)
		return (n_char_wr);
	return (0);
}
