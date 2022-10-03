/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_void_ptr_hex.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:21:02 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/10/03 19:28:36 by xrodrigu         ###   ########.fr       */
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
		ft_printf_char(c);
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
	size_t	address;

	address = (size_t)ptr;
	ft_putstr_fd("0x", 1);
	ft_printf_hex_long(address);
}
