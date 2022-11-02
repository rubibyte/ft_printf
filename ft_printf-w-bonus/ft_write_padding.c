/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_padding.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:13:53 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/01 20:13:55 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_padding(t_ftprintf *arg_data, int n, char p)
{
	int	i;
	int	temp_n;

	i = -1;
	while (++i < n)
	{
		temp_n = (int)write(STDOUT_FILENO, &p, 1);
		if (temp_n < 0)
			return (temp_n);
		arg_data->n_printed += temp_n;
	}
	return (0);
}
