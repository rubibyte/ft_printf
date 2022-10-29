/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:34:46 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/09/22 13:52:51 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*new_s;
	unsigned int	i;
	unsigned int	j;

	new_s = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!new_s)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new_s[i] = (char)s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new_s[i + j] = (char)s2[j];
		j++;
	}
	new_s[i + j] = '\0';
	return (new_s);
}
