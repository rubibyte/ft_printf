/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 10:50:30 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/09/19 01:36:32 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	i;

	d = (char *)dst;
	s = (char *)src;
	i = -1;
	if (!dst && !src)
		return (NULL);
	if (d < s)
	{
		while (++i < len)
			d[i] = s[i];
	}
	else
	{
		while (++i < len)
			d[len - i - 1] = s[len - i - 1];
	}
	return (dst);
}
