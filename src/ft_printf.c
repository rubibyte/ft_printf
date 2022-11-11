/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 23:19:35 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/11 05:19:17 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h" //necesario????? hay que poner siempre el header al que pertenece la funcion aunque no aporte nada??
#include "ft_printf_utils.h"

static int	ft_check_type(va_list args, const char fmt)
{
	char	c;

	if (fmt == 'c')
	{
		c = va_arg(args, int);
		return ((int)write(STDOUT_FILENO, &c, 1));
	}
	else if (fmt == '%')
		return (write(1, "%", 1));
	else if (fmt == 's')
		return (ft_printf_str(va_arg(args, char *)));
	else if (fmt == 'p')
		return (ft_printf_void_ptr_hex(va_arg(args, void *)));
	else if (fmt == 'd' || fmt == 'i')
		return (ft_printf_int(va_arg(args, int)));
	else if (fmt == 'u')
		return (ft_printf_uint_base(va_arg(args, unsigned int), DEC));
	else if (fmt == 'x')
		return (ft_printf_uint_base(va_arg(args, unsigned int), HEX_LC));
	else if (fmt == 'X')
		return (ft_printf_uint_base(va_arg(args, unsigned int), HEX_UC));
	return (0);
}

static int	ft_check_fmt(va_list args, const char *fmt)
{
	int	i;
	int	temp_n;
	int	bytes_printed;

	i = -1;
	bytes_printed = 0;
	while (fmt[++i])
	{
		if (fmt[i] == '%')
			temp_n = ft_check_type(args, fmt[++i]);
		else
			temp_n = (int)write(STDOUT_FILENO, &fmt[i], 1);
		if (temp_n < 0)
			return (temp_n);
		bytes_printed += temp_n;
	}
	return (bytes_printed);
}

int	ft_printf(const char *fmt, ...)
{
	int		bytes_printed;
	va_list	args;

	va_start(args, fmt);
	bytes_printed = ft_check_fmt(args, fmt);
	va_end(args);
	return (bytes_printed);
}
