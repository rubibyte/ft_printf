/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_there_is.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:10:45 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/01 20:12:36 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_there_is_flag(const char *fmt, int i)
{
	if (fmt[i] && ft_strchr("# +-0", fmt[i]))
		return (1);
	return (0);
}

int	ft_there_is_width(const char *fmt, int i)
{
	if (fmt[i] && ft_strchr("123456789", fmt[i]))
		return (1);
	return (0);
}

int	ft_there_is_precision(const char *fmt, int i)
{
	if (fmt[i] == '.' && ft_strchr("0123456789", fmt[i + 1 ]))
		return (1);
	else if (fmt[i] == '.' && fmt[i + 1] == '*')
		return (1);
	return (0);
}

/*int	ft_there_is_precision_asterisk(const char *fmt, int i)
{
	if (fmt[i] == '.' && fmt[i + 1] == '*')
		return (1);
	return (0);
}*/

int	ft_there_is_type(const char *fmt, int i)
{
	if (fmt[i] && ft_strchr("cspdiuxX%", fmt[i]))
		return (1);
	return (0);
}
	
