/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_str_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 23:02:24 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/11 20:08:25 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils_bonus.h"

int	ft_write_str(t_ftprintf *arg_data, char *str)
{
	int	i;
	int	temp_n;

	i = -1;
	while (str[++i])
	{
		temp_n = (int)write(STDOUT_FILENO, &str[i], 1);
		if (0 > temp_n)
			return (-1);
		arg_data->bytes_printed += temp_n;
	}
	return (0);
}
