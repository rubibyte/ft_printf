/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 23:02:24 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/10/18 18:38:43 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_str(t_ftprintf arg_data, char *str)
{
	int		i;
	int	temp_n;

	i = -1;
	if (!str)
		str = (char *)"(null)";
	while (str[++i])
	{
		temp_n = (int)write(STDOUT_FILENO, &str[i], 1);
		if (temp_n < 0)
			return (-1);
		arg_data->n_printed += temp_n;
	}
	return (0);
}
