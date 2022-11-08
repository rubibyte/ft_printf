/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:35:59 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/08 01:56:36 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_BONUS_H
# define FT_PRINTF_UTILS_BONUS_H

# include <stdarg.h>
# include "libft.h"

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

int			ft_check_fmt(t_ftprintf *arg_data, const char *fmt, int i);

int			ft_check_valid_format(const char *fmt, int i);

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
