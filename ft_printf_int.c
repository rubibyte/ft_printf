/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 23:06:30 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/10/18 18:38:34 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_int(int n)
{
	char	*num_str;
	int		n_wr;

	num_str = ft_itoa(n);
	n_wr = ft_printf_str(num_str);
	//n_wr = write(1, num_str, ft_strlen(num_str));
	free(num_str);
	//num_str = NULL;
	return (n_wr);
}
