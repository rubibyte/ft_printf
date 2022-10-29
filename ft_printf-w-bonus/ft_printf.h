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
# include <limits.h>
# include "libft/include/libft.h"

# define UINT           unsigned int
# define HEX_UC			(char *)"0123456789ABCDEF"
# define HEX_LC			(char *)"0123456789abcdef"
# define DEC            (char *)"0123456789"

char	*ft_unsignedtoa_base(size_t n, char *base);

size_t	ft_nbrlen_base(long n, char *base);

char	*ft_uitoa_base(unsigned int n, char *base);

ssize_t	ft_printf_int(int n);

ssize_t	ft_printf_str(char *str);

ssize_t	ft_printf_uint_base(unsigned int n, char *base);

ssize_t	ft_printf_void_ptr_hex(void *ptr);

int		ft_printf(const char *fmt, ...);

#endif
