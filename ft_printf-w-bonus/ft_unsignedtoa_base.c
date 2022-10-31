/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:22:06 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/10/18 18:37:49 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char	*ft_unsignedtoa_base(size_t n, char *base)
{
	char	*num_str;
	size_t	len;

	len = ft_unsignedlen_base(n, base);
	num_str = (char *)malloc(len * sizeof(char) + 1);
	if (!num_str)
		return (NULL);
	if (n == 0)
		num_str[0] = base[0];
	num_str[len] = '\0';
	while (n)
	{
		--len;
		num_str[len] = base[n % ft_strlen(base)];
		n /= ft_strlen(base);
	}
	return (num_str);
}
