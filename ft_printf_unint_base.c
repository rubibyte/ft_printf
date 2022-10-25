/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unint_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:49:01 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/10/18 18:38:56 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_printf_unint_base(unsigned int n, char *base)
{
	char	*num_str;
	ssize_t	n_wr;

	num_str = ft_uitoa_base(n, base);
	if (!num_str)
		return (-1);
	n_wr = ft_printf_str(num_str);
	free(num_str);
	return (n_wr);
}
