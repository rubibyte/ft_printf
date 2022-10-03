/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_up.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:14:42 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/10/03 18:54:43 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	ft_printf_hex_up(unsigned int n)
{
	char	*hex_up;
	char	c;

	hex_up = ft_strdup("0123456789ABCDEF");
	if (n < 0)
		ft_printf_hex_up(4294967296 + n);
	else if (n <= 16)
	{
		c = hex_up[n];
		ft_printf_char(c);
		free(hex_up);
	}
	else
	{
		ft_printf_hex_up(n / 16);
		ft_printf_hex_up(n % 16);
	}
}
