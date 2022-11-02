/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:06:02 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/02 00:58:45 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(t_ftprintf *arg_data)
{
	//printf("hola");
	char	c;
	int		temp_n;
	
	if (arg_data->percentage)
		c = '%';
	else
		c = va_arg(arg_data->args, int);
	if (arg_data->width > 1 && !arg_data->dash)
		if (0 > ft_padding(arg_data, arg_data->width - 1, ' '))
			return (-1);
	temp_n = (int)write(STDOUT_FILENO, &c, 1);
	if (0 > temp_n)
		return (-1);
	//printf("temp_n: %d\n", temp_n);
	if (arg_data->width > 1 && arg_data->dash)
		if (0 > ft_padding(arg_data, arg_data->width - 1, ' '))
			return (-1);
	arg_data->n_printed += temp_n;
	return (0);
}
