/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignedlen_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:29:08 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/04 19:29:27 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_unsignedlen_base(size_t n, char *base)
{
	size_t	size;

	if (n == 0)
		return (1);
	size = 0;
	while (n)
	{
		size++;
		n /= ft_strlen(base);
	}
	return (size);
}
