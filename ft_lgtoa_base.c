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

char	*ft_lgtoa_base(size_t n, char *base)
{
	char 	*num_str;
	size_t	len; //try unsigned long, print adress in ptr hex, if void * NULL = "0x0"

	len = ft_nbrlen_base(n, base);
	num_str = (char *)malloc(len * sizeof(char) + 1);
	if (!num_str)
		return (NULL);
	num_str[len] = '\0';
	while (n)
	{
		--len;
		num_str[len] = base[n % ft_strlen(base)];
		n /= ft_strlen(base);
	}
	return (num_str);
}
