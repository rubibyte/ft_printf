/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:28:47 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/09/30 17:29:01 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;
	size_t	s_len;

	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len - (size_t)start < len)
		sub_str = (char *)malloc((s_len - (size_t)start) * sizeof(char) + 1);
	else
		sub_str = (char *)malloc(len * sizeof(char) + 1);
	if (!sub_str)
		return (NULL);
	i = 0;
	while (i < len && s_len > (size_t)start + i)
	{
		sub_str[i] = s[(size_t)start + i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
