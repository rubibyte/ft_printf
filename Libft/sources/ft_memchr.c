/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:48:43 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/10/01 18:48:03 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*uc_s;

	uc_s = (unsigned char *) s;
	i = -1;
	while (++i < (int)n)
		if (uc_s[i] == (unsigned char)c)
			return ((void *) &uc_s[i]);
	return (0);
}
