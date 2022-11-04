/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:08:35 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/04 15:33:32 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_str_max_len(t_ftprintf *arg_data, char *str, int max_len)
{
	int	i;
	int	temp_n;

	if (!str)
		str = (char *)"(null)";
	i = -1;
	while (str[++i] && i < max_len)
	{
		temp_n = (int)write(STDOUT_FILENO, &str[i], 1);
		if (0 > temp_n)
			return (-1);
		arg_data->n_printed += temp_n;
	}
	return (0);
}

static int	ft_valid_width(t_ftprintf *arg_data, char *str)
{
	int	str_len;

	str_len = (int)ft_strlen(str);
	if (arg_data->dot && arg_data->precision < str_len)
		str_len = arg_data->precision;
	if (arg_data->width > str_len)
		return (1);
	return (0);
}

static int	ft_padd_width(t_ftprintf *arg_data, char *str)
{
	int	str_len;

	str_len = (int)ft_strlen(str);
	if (arg_data->dot && arg_data->precision < str_len)
		str_len = arg_data->precision;
	return (arg_data->width - str_len);
}

int	ft_printf_str(t_ftprintf *arg_data)
{
	char	*str;

	ft_pull_precision_asterisk(arg_data);
	str = va_arg(arg_data->args, char *);
	if (!str)
		str = (char *)"(null)";
	if (!arg_data->dash && ft_valid_width(arg_data, str))
		if (0 > ft_padding(arg_data, ft_padd_width(arg_data, str), ' '))
			return (-1);
	if (arg_data->dot)
		if (0 > ft_write_str_max_len(arg_data, str, arg_data->precision))
			return (-1);
	if (!arg_data->dot)
		if (0 > ft_write_str(arg_data, str))
			return (-1);
	if (arg_data->dash && ft_valid_width(arg_data, str))
		if (0 > ft_padding(arg_data, ft_padd_width(arg_data, str), ' '))
			return (-1);
	return (0);
}
