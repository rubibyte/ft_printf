/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_there_is.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:10:45 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/07 19:58:19 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_there_is_flag(const char *fmt, int i)
{
	return (fmt[i] && ft_strchr("# +-0", fmt[i]));
}

static int	ft_there_is_width(const char *fmt, int i)
{
	return (fmt[i] && ft_strchr("123456789", fmt[i]));
}

static int	ft_there_is_precision(const char *fmt, int i)
{
	return (fmt[i] == '.');
}

static int	ft_there_is_type(const char *fmt, int i)
{
	return (fmt[i] && ft_strchr("cspdiuxX%", fmt[i]));
}

int	ft_check_valid_format(const char *fmt, int i)
{
	if (ft_there_is_flag(fmt, i))
		while (fmt[i] && ft_strchr("# +-0", fmt[i]))
			i++;
	if (ft_there_is_width(fmt, i))
		while (fmt[i] && ft_strchr("0123456789", fmt[i]))
			i++;
	if (ft_there_is_precision(fmt, i))
	{
		i++;
		if (fmt[i] == '*')
			i++;
		else
			while (fmt[i] && ft_strchr("0123456789", fmt[i]))
				i++;
	}
	return (ft_there_is_type(fmt, i));
}
