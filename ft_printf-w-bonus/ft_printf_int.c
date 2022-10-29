/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 23:06:30 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/10/18 18:38:34 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_printf_int(int n)
{
	char	*num_str;
	ssize_t	n_wr;

	num_str = ft_itoa(n);
	if (!num_str)
		return (-1);
	n_wr = ft_printf_str(num_str);
	free(num_str);
	return (n_wr);
}
