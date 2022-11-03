/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 21:06:13 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/03 23:32:42 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/include/libft.h"

# include <stdio.h> //temporal for doing tests

# define HEX_UC			(char *)"0123456789ABCDEF"
# define HEX_LC			(char *)"0123456789abcdef"
# define DEC			(char *)"0123456789"

typedef struct s_ftprintf
{
	va_list	args;
	int8_t	sharp;
	int8_t	zero;
	int8_t	dash;
	int8_t	space;
	int8_t	sign;
	int		width;
	int8_t	dot;
	int8_t	asterisk;
	int		precision;
	int		percentage;
	int		n_printed;
}				t_ftprintf;

int			ft_fetch_arg_data(t_ftprintf *arg_data, const char *fmt, int i);

t_ftprintf	*ft_init_arg_data(t_ftprintf *arg_data);

void		ft_reset_arg_data(t_ftprintf *arg_data);

int			ft_printf_arg(t_ftprintf *arg_data, const char fmt);

int			ft_printf_char(t_ftprintf *arg_data);

int			ft_printf_int(t_ftprintf *arg_data);

int			ft_printf_str(t_ftprintf *arg_data);

int			ft_printf_unsigned_int_hex(t_ftprintf *arg_data, const char fmt);

int			ft_printf_unsigned_int(t_ftprintf *arg_data);

int			ft_printf_void_ptr_hex(t_ftprintf *arg_data);

int			ft_printf(const char *fmt, ...);

int			ft_there_is_flag(const char *fmt, int i);

int			ft_there_is_width(const char *fmt, int i);

int			ft_there_is_precision(const char *fmt, int i);

int			ft_there_is_type(const char *fmt, int i);

size_t		ft_unsignedlen_base(size_t n, char *base);

char		*ft_unsignedtoa_base(size_t n, char *base);

int			ft_write_int(t_ftprintf *arg_data, long n);

int			ft_padding(t_ftprintf *arg_data, int n, char p);

int			ft_write_str(t_ftprintf *arg_data, char *str);

int			ft_write_uint_base(t_ftprintf *arg_data,
				unsigned int n, char *base);

int			ft_write_void_ptr_hex(t_ftprintf *arg_data, void *ptr);

void		ft_pull_precision_asterisk(t_ftprintf *arg_data);

int			ft_check_precision(t_ftprintf *arg_data, long n);

int			ft_check_precision_base(t_ftprintf *arg_data, unsigned int n);

#endif
