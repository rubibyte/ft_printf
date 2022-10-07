/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 21:06:13 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/10/07 21:46:08 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTFLIB_H
# define FT_PRINTFLIB_H

# include <unistd.h>
# include <stdarg.h>

# include "libft/libft.h"

void	ft_printf_int(int n);

void	ft_printf_str(char *str);

void	ft_printf_unint_base(unsigned int n, char *base);

void	ft_printf_void_ptr_hex(void *ptr);

#endif
