/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:57:32 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/09/30 23:35:38 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*buffer;
	size_t	i;

	buffer = (char *)malloc(count * size);
	i = 0;
	if (!buffer)
		return (NULL);
	while (i < count * size)
		buffer[i++] = 0;
	return ((void *)buffer);
}
