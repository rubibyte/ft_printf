/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 21:06:13 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/10/18 02:40:32 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTFLIB_H
# define FT_PRINTFLIB_H

# include <unistd.h>
# include <stdarg.h>

# include "libft/libft.h"

char	*ft_lgtoa_base(size_t n, char *base);

size_t	ft_nbrlen(long n);

size_t	ft_nbrlen_base(long n, char *base);

char	*ft_uitoa_base(unsigned int n, char *base);

int		ft_printf_int(int n);

int		ft_printf_str(char *str);

int		ft_printf_unint_base(unsigned int n, char *base);

int		ft_printf_void_ptr_hex(void *ptr);

int		ft_printf(const char *format, ...);

#endif
