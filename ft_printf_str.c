/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 23:02:24 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/10/17 20:14:09 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printflib.h"

int	ft_printf_str(char *str)
{
	int	n_char_wr;
	int	i;
	int	temp_n;

	i = -1;
	n_char_wr = 0;
	while (str[++i])
	{
		temp_n = (int)write(1, &str[i], 1);
		if (temp_n < 0)
			return temp_n;
		n_char_wr += temp_n;
	}
	return (n_char_wr);	
}
