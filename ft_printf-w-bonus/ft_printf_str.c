/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:08:35 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/01 23:36:26 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_str(t_ftprintf *arg_data)
{
	char	*str;

	str = va_arg(arg_data->args, char *);
	if (!str)
		str = (char *)"(null)";
	if (arg_data->width > (int)ft_strlen(str) && !arg_data->dash)
		if (0 > ft_padding(arg_data, arg_data->width - ft_strlen(str), ' '))
			return (-1);
	if (0 > ft_write_str(arg_data, str))
		return (-1);
	if (arg_data->width > (int)ft_strlen(str) && arg_data->dash)
		if (0 > ft_padding(arg_data, arg_data->width - ft_strlen(str), ' '))
			return (-1);
	return (0);
}
