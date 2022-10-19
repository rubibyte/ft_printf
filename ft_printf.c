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

//#include <limits.h>

//#include <stdio.h>

static int	ft_check_type(va_list args, const char *fmt, int i)
{
	int		n_wr;
	char	c;

	n_wr = 0;
	if (fmt[i] == 'c')
	{
		c = va_arg(args, int);
		n_wr += (int)write(STDOUT_FILENO, &c, 1);
	}
	else if (fmt[i] == '%')
		n_wr += (int)write(1, "%", 1);
	else if (fmt[i] == 's')
		n_wr += ft_printf_str(va_arg(args, char *));
	else if (fmt[i] == 'p')
		n_wr += ft_printf_void_ptr_hex(va_arg(args, void *));
	else if (fmt[i] == 'd' || fmt[i] == 'i')
		n_wr += ft_printf_int(va_arg(args, int));
	else if (fmt[i] == 'u')
		n_wr += ft_printf_unint_base(va_arg(args, UNINT), DEC);
	else if (fmt[i] == 'x')
		n_wr += ft_printf_unint_base(va_arg(args, UNINT), HEX_LC);
	else if (fmt[i] == 'X')
		n_wr += ft_printf_unint_base(va_arg(args, UNINT), HEX_UC);
	return (n_wr);
}

int	ft_printf(const char *fmt, ...)
{
	int		i;
	int		n_wr;
	va_list	args;
	int		temp_n;

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

/*int	main(void)
{
	printf(" %p %p \n\n", LONG_MIN, LONG_MAX);

	ft_printf(" %p %p \n\n", LONG_MIN, LONG_MAX);
	return (0);
}
*/




/*int	main(void)
{
	int	err_printf;
	int	err_ft_printf;
	void	*ptr;
	char	c;

	c = 'h';
	ptr = &c;

	err_printf = printf("asd%%fa char: %c, str: %s, void *: %p, decimal: %d,\
	 addindex: %i, unsigned decimal: %u, hex lowercase: %x, hex uppercase: \
	%X\n",'a', "frank%%%%", ptr, 123456, 654321, -123, 3456, -3456);

	err_ft_printf = ft_printf("asd%%fa char: %c, str: %s, void *: %p, decimal: \
	%d, integer: %i, unsigned decimal: %u, hex lowercase: %x, \
	uppercase: %X\n", 'b', "frank%%%%", ptr, 123456, 654321, -123, 3456, -3456);

	printf("\n\nreturn printf: %d\nreturn ft_printf: %d",\
	err_printf, err_ft_printf);
	return (0);
}*/
