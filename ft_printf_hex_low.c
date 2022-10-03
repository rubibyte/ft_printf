/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_low.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:49:59 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/10/03 19:20:08 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	ft_printf_hex_low(unsigned int n)
{
	char	*hex_low;
	char	c;

	hex_low = ft_strdup("0123456789abcdef");
	if (n < 0)
		ft_printf_hex_low(4294967296 + n);
	else if (n <= 16)
	{
		c = hex_low[n];
		ft_printf_char(c);
		free(hex_low);
	}
	else
	{
		ft_printf_hex_low(n / 16);
		ft_printf_hex_low(n % 16);
	}
}
