/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:35:30 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/09/24 23:42:43 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_absval(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

static size_t	ft_nbrlen(long n)
{
	size_t	size;

	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
		size++;
	while (n)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
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
