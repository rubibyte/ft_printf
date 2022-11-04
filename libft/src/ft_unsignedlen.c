/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignedlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:27:16 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/04 19:28:21 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_unsignedlen(size_t n)
{
	size_t	size;

	if (n == 0)
		return (1);
	size = 0;
	while (n)
	{
		size++;
		n /= 10;
	}
	return (size);
}
