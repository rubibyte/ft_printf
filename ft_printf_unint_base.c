/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unint_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:49:01 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/10/14 18:21:42 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

#include <stdio.h>

int	ft_printf_unint_base(unsigned int n, char *base)
{
	char	c;
	int		n_char_wr;
	
	if (n < 0)
		ft_printf_unint_base(4294967296 + n, base);
	if (n <= ft_strlen(base))
	{
		c = base[n];
		n_char_wr = (int)write(1, &c, 1);
		if (n_char_wr < 0)
			return (n_char_wr);
	}
	else
	{
		ft_printf_unint_base(n / ft_strlen(base), base);
		ft_printf_unint_base(n % ft_strlen(base), base);
	}
	return (0);
}



/*int	main(void)
{
	ft_printf_unint_base(-1, "0123456789");

	printf("\n%u", -1);
	return (0);
}*/
