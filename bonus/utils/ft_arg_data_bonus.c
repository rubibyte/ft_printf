/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_data_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:58:56 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/11 20:10:28 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils_bonus.h"

t_ftprintf	*ft_init_arg_data(t_ftprintf *arg_data)
{
	arg_data->sharp = 0;
	arg_data->zero = 0;
	arg_data->dash = 0;
	arg_data->space = 0;
	arg_data->sign = 0;
	arg_data->width = 0;
	arg_data->dot = 0;
	arg_data->asterisk = 0;
	arg_data->precision = 0;
	arg_data->percentage = 0;
	arg_data->bytes_printed = 0;
	return (arg_data);
}

void	ft_reset_arg_data(t_ftprintf *arg_data)
{
	arg_data->sharp = 0;
	arg_data->zero = 0;
	arg_data->dash = 0;
	arg_data->space = 0;
	arg_data->sign = 0;
	arg_data->width = 0;
	arg_data->dot = 0;
	arg_data->asterisk = 0;
	arg_data->precision = 0;
	arg_data->percentage = 0;
}
