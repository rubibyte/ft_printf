/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:50:43 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/10/01 18:48:19 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s1_cpy;
	int		i;

	s1_cpy = (char *)malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (!s1_cpy)
		return (NULL);
	i = -1;
	while (s1[++i])
		s1_cpy[i] = s1[i];
	s1_cpy[i] = '\0';
	return (s1_cpy);
}	
