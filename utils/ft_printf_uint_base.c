/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:49:01 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/07 21:15:02 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int	ft_printf_uint_base(unsigned int n, char *base)
{
	char	*num_str;
	int		bytes_printed;

	num_str = ft_unsignedtoa_base(n, base);
	if (!num_str)
		return (-1);
	bytes_printed = ft_printf_str(num_str);
	free(num_str);
	return (bytes_printed);
}
