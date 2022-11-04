/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignedtoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:31:36 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/04 19:53:37 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_unsignedtoa(size_t n)
{
	char	*num_str;
	size_t	len;

	len = ft_unsignedlen(n);
	num_str = (char *)malloc(len * sizeof(char) + 1);
	if (!num_str)
		return (NULL);
	num_str[len] = '\0';
	if (n == 0)
		num_str[0] = '0';
	while (n)
	{
		--len;
		num_str[len] = ft_absval(n % 10) + '0';
		n /= 10;
	}
	return (num_str);
}
