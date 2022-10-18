/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unint_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:49:01 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/10/18 18:38:56 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_unint_base(unsigned int n, char *base)
{
	char	*num_str;
	int		n_wr;

	num_str = ft_uitoa_base(n, base);
	n_wr = (int)write(1, num_str, ft_strlen(num_str));
	free(num_str);
	num_str = NULL;
	return (n_wr);
}
