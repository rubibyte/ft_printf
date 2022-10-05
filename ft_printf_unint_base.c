/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unint_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:49:01 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/10/05 21:03:05 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

#include <stdio.h>

void	ft_printf_unint_base(unsigned int n, char *base)
{
	char	c;
	
	if (n < 0)
		ft_printf_unint_base(4294967296 + n, base);
	if (n <= ft_strlen(base))
	{
		c = base[n];
		write(1, &c, 1);
	}
	else
	{
		ft_printf_unint_base(n / ft_strlen(base), base);
		ft_printf_unint_base(n % ft_strlen(base), base);
	}
}
