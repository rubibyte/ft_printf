/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 21:06:13 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/10/24 00:06:19 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/include/libft.h"

# define HEX_UC			(char *)"0123456789ABCDEF"
# define HEX_LC			(char *)"0123456789abcdef"
# define DEC            (char *)"0123456789"

int	ft_printf_int(int n);

int	ft_printf_str(char *str);

int	ft_printf_uint_base(unsigned int n, char *base);

int	ft_printf_void_ptr_hex(void *ptr);

int	ft_printf(const char *fmt, ...);

#endif
