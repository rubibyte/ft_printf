/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 23:06:30 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/10/13 00:16:21 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	ft_printf_int(int n)
{
	char	*num_str;
	int		n_char_wr;

	num_str = ft_itoa(n);
	n_char_wr = write(1, num_str, ft_strlen(num_str));
	free(num_str);
	num_str = NULL;
	return (n_char_wr);
}






/*int	ft_printf_int(int n)
{
	char	c;
	int		n_char_wr;

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
		n_char_wr = write(1, &c, 1);
		if (n_char_wr < 0)
			return (n_char_wr);
	}
	else
	{
		ft_printf_int(n / 10);
		ft_printf_int(n % 10);
	}
	return (0);
}*/
