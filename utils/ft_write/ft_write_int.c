/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 23:06:30 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/16 21:31:01 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int	ft_write_int(t_ftprintf *arg_data, long n)
{
	char	*num_str;

	num_str = ft_ltoa(n);
	if (!num_str)
		return (-1);
	if (0 > ft_write_str(arg_data, num_str))
	{
		free(num_str);
		return (-1);
	}
	free(num_str);
	return (0);
}
