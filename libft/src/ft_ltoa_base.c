/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:38:37 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/04 19:55:22 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ltoa_base(long n, char *base)
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
		num_str[0] = base[0];
	while (n)
	{
		--len;
		num_str[len] = base[ft_absval(n % ft_strlen(base))];
		n /= ft_strlen(base);
	}
	return (num_str);
}
