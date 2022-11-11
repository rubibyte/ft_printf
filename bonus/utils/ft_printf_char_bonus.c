/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:06:02 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/11 19:44:30 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils_bonus.h"

int	ft_printf_char(t_ftprintf *arg_data)
{
	char	c;
	int		temp_n;

	if (arg_data->percentage)
		c = '%';
	else
		c = va_arg(arg_data->args, int);
	if (!arg_data->dash && arg_data->width > 1)
		if (0 > ft_padding(arg_data, arg_data->width - 1, ' '))
			return (-1);
	temp_n = (int)write(STDOUT_FILENO, &c, 1);
	if (0 > temp_n)
		return (-1);
	arg_data->n_printed += temp_n;
	if (arg_data->dash && arg_data->width > 1)
		if (0 > ft_padding(arg_data, arg_data->width - 1, ' '))
			return (-1);
	return (0);
}
