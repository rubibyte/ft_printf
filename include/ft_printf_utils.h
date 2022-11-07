/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:03:58 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/07 23:21:05 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include "libft.h"

# define HEX_UC			(char *)"0123456789ABCDEF"
# define HEX_LC			(char *)"0123456789abcdef"
# define DEC            (char *)"0123456789"

int	ft_printf_int(int n);

int	ft_printf_str(char *str);

int	ft_printf_uint_base(unsigned int n, char *base);

int	ft_printf_void_ptr_hex(void *ptr);

#endif
