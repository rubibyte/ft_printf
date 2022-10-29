/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 23:19:35 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/10/18 21:46:17 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_type(va_list args, const char *fmt, int i)
{
	char	c;
	ssize_t	n_wr;

	n_wr = 0;
	if (fmt[i] == 'c')
	{
		c = va_arg(args, int);
		n_wr += write(STDOUT_FILENO, &c, 1);
	}
	else if (fmt[i] == '%')
		n_wr += write(1, "%", 1);
	else if (fmt[i] == 's')
		n_wr += ft_printf_str(va_arg(args, char *));
	else if (fmt[i] == 'p')
		n_wr += ft_printf_void_ptr_hex(va_arg(args, void *));
	else if (fmt[i] == 'd' || fmt[i] == 'i')
		n_wr += ft_printf_int(va_arg(args, int));
	else if (fmt[i] == 'u')
		n_wr += ft_printf_uint_base(va_arg(args, UINT), DEC);
	else if (fmt[i] == 'x')
		n_wr += ft_printf_uint_base(va_arg(args, UINT), HEX_LC);
	else if (fmt[i] == 'X')
		n_wr += ft_printf_uint_base(va_arg(args, UINT), HEX_UC);
	return ((int)n_wr);
}

int	ft_printf(const char *fmt, ...)
{
	int		i;
	int		n_wr;
	int		temp_n;
	va_list	args;

	i = 0;
	n_wr = 0;
	temp_n = 0;
	va_start(args, fmt);
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
			temp_n = ft_check_type(args, fmt, ++i);
		else
			temp_n = (int)write(STDOUT_FILENO, &fmt[i], 1);
		if (temp_n < 0)
			return (temp_n);
		n_wr += temp_n;
		i++;
	}
	va_end(args);
	return (n_wr);
}
