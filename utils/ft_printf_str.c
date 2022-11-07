/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 23:02:24 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/07 21:14:55 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int	ft_printf_str(char *str)
{
	int	i;
	int	temp_n;
	int	bytes_printed;

	i = -1;
	bytes_printed = 0;
	if (!str)
		str = (char *)"(null)";
	while (str[++i])
	{
		temp_n = (int)write(STDOUT_FILENO, &str[i], 1);
		if (0 > temp_n)
			return (-1);
		bytes_printed += temp_n;
	}
	return (bytes_printed);
}
