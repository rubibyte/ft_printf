/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:50:53 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/09/23 19:52:54 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*maped_str;
	unsigned int	i;

	maped_str = (char *)malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!maped_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		maped_str[i] = f(i, s[i]);
		i++;
	}
	maped_str[i] = '\0';
	return (maped_str);
}
