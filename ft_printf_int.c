/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 23:06:30 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/10/05 20:02:28 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	ft_printf_int(int n)
{
	char	c;

	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		c = '-';
		write(1, &c, 1);
		n *= -1;
		ft_printf_int(n);
	}
	else if (n <= 9)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_printf_int(n / 10);
		ft_printf_int(n % 10);
	}
}
