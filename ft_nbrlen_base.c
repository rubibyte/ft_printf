/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:16:06 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/10/17 20:29:31 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

size_t	ft_nbrlen_base(long n, char *base)
{
	size_t	size;

	if (n == 0)
		return (1);
	size = 0;
//	if (n < 0)
//		size++; not necessary in when using unsigned but don't delete to be reliable
	while (n)
	{
		size++;
		n /= ft_strlen(base);
	}
	return (size);
}
