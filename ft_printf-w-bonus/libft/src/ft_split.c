/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:21:52 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/10/01 22:47:05 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(char const *s, char const c)
{
	int		i;
	size_t	count;

	i = -1;
	count = 0;
	while (s[++i])
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
	return (count);
}

void	*ft_free(char **arr, size_t size)
{
	while (size--)
	{
		free(arr[size]);
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char const c)
{
	char			**split_s;
	size_t			i;
	unsigned int	j;
	int				start;

	split_s = (char **)malloc((ft_word_count(s, c) + 1) * sizeof(char **));
	if (!split_s)
		return (NULL);
	i = -1;
	j = 0;
	start = -1;
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			split_s[j++] = ft_substr(s, (unsigned int)start, i - (size_t)start);
			if (!split_s[j - 1])
				return (ft_free(split_s, j));
			start = -1;
		}
	}
	split_s[j] = 0;
	return (split_s);
}
