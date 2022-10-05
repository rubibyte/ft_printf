/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_void_ptr_hex.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:21:02 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/10/05 21:16:03 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static void	ft_printf_hex_long(size_t n)
{
	char	*hex_low;
	char	c;

	hex_low = ft_strdup("0123456789abcdef");
	if (n <= 16)
	{
		c = hex_low[n];
		write(1, &c, 1);
		free(hex_low);
	}
	else
	{
		ft_printf_hex_long(n / 16);
		ft_printf_hex_long(n % 16);
	}
}

void	ft_printf_void_ptr_hex(void *ptr)
{
	//size_t	address;

	//address = (size_t)ptr;
	write(1, "0x", 2);
	ft_printf_hex_long((size_t)ptr);
}
