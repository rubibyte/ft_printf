/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:19:02 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/10/17 20:31:20 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printflib.h"

char	*ft_uitoa_base(unsigned int n, char *base)
{
	char	*num_str;
	size_t	len;

	if ((int)n < 0)
		ft_uitoa_base(4294967296 + n, base);
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
