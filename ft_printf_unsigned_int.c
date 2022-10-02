/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 23:26:55 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/10/02 23:32:15 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	ft_printf_unsigned_int(unsigned int n)
{
	char	c;

	if (n <= 9)
	{
		c = n + '0';
		ft_putchar_fd(c, 1);
	}
	else
	{
		ft_printf_unsigned_int(n / 10);
		ft_printf_unsigned_int(n % 10);
	}
}
