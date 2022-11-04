/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:01:18 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/04 19:42:00 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ltoa(long n)
{
	char	*num_str;
	size_t	len;

	len = ft_nbrlen(n);
	num_str = (char *)malloc(len * sizeof(char) + 1);
	if (!num_str)
		return (NULL);
	num_str[len] = '\0';
	if (n < 0)
		num_str[0] = '-';
	else if (n == 0)
		num_str[0] = '0';
	while (n)
	{
		--len;
		num_str[len] = ft_absval(n % 10) + '0';
		n /= 10;
	}
	return (num_str);
}
