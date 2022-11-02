/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:15:06 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/02 13:51:16 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pull_precision_asterisk(t_ftprintf *arg_data)
{
	if (arg_data->asterisk)
		arg_data->precision = va_arg(arg_data->args, int);
}

int	ft_check_precision(t_ftprintf *arg_data, long n)
{
	int	n_len;
	
	n_len = (int)ft_nbrlen(n);
	if (arg_data->precision > n_len)
		if (0 > ft_padding(arg_data, arg_data->precision - n_len, '0'))
			return (-1);
	return (0);
}

int	ft_check_precision_base(t_ftprintf *arg_data, unsigned int n)
{
	int	n_len;

	n_len = (int)ft_unsignedlen_base(n, HEX_LC);
	if (arg_data->precision > n_len)
		if (0 > ft_padding(arg_data, arg_data->precision - n_len, '0'))
			return (-1);
	return (0);
}
