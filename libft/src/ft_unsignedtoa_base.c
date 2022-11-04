/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignedtoa_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:35:01 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/04 19:54:25 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_unsignedtoa_base(size_t n, char *base)
{
	char	*num_str;
	size_t	len;

	len = ft_unsignedlen_base(n, base);
	num_str = (char *)malloc(len * sizeof(char) + 1);
	if (!num_str)
		return (NULL);
	num_str[len] = '\0';
	if (n == 0)
		num_str[0] = base[0];
	while (n)
	{
		--len;
		num_str[len] = base[n % ft_strlen(base)];
		n /= ft_strlen(base);
	}
	return (num_str);
}
