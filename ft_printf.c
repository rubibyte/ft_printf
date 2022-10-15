/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 23:19:35 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/10/14 23:31:04 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printflib.h"

#include <stdio.h>

static int	ft_check_type(va_list args, const char *format, int i)
{
	int	n_char_wr;
	char	c;
	int		len;
	
	n_char_wr = 0;
	if (format[i] == 'c')
	{
		c = va_arg(args, int);
		n_char_wr += (int)write(1, &c, 1);
	}
	else if (format[i] == '%')
		n_char_wr += (int)write(1, "%", 1);
	else if (format[i] == 's')
		n_char_wr += ft_printf_str(va_arg(args, char *));
	else if (format[i] == 'p')
		n_char_wr += ft_printf_void_ptr_hex(va_arg(args, void *));
	else if (format[i] == 'd' || format[i] == 'i')
		n_char_wr += ft_printf_int(va_arg(args, int));
	else if (format[i] == 'u')
		n_char_wr += ft_printf_unint_base(va_arg(args, unsigned int), "0123456789");
	else if (format[i] == 'x')
		n_char_wr += ft_printf_unint_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (format[i] == 'X')
		n_char_wr += ft_printf_unint_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	return (n_char_wr);
}


int	ft_printf(const char *format, ...)
{
	int	i;
	int	n_char_wr;
	va_list	args;
	int	temp_n;

	i = 0;
	n_char_wr = 0;
	temp_n = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			temp_n = ft_check_type(args, format, ++i);
		else
			temp_n = (int)write(1, &format[i], 1);
		if (temp_n < 0)
			return (temp_n);
		n_char_wr += temp_n;
		i++;
	}
	va_end(args);
	return (n_char_wr);
}

int	main(void)
{
	int	err_printf;
	int	err_ft_printf;
	void	*ptr;
	char	c;

	c = 'h';
	ptr = &c;

	err_printf = printf("asd%%fa char: %c, str: %s, void *: %p, decimal: %d, integer: %i, unsigned decimal: %u, hex lowercase: %x, hex uppercase: %X\n",'a', "frank%%%%", ptr, 123456, 654321, -123, 3456, -3456);

	err_ft_printf = ft_printf("asd%%fa char: %c, str: %s, void *: %p, decimal: %d, integer: %i, unsigned decimal: %u, hex lowercase: %x, hex uppercase: %X\n", 'b', "frank%%%%", ptr, 123456, 654321, -123, 3456, -3456);

	printf("\n\nreturn printf: %d\nreturn ft_printf: %d", err_printf, err_ft_printf);
	return (0);
}
