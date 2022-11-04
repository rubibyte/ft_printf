/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single -tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:51:38 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/04 15:55:52 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int	a, b, c, d;

	a = printf("%10.*d onespace\n", 5, 15);
	b = printf("%10.*d onespace\n", 5, 15);
	c = ft_printf("%10.*d onespace\n", 5, 15);
	d = ft_printf("%10.*d onespace\n", 5, 15);
	printf("\nresultados por orden: %i, %i, %i, %i\n\n", a, b, c, d);

	a = printf("%10.*d onespace\n", 0, 0);
	b = printf("%10.*d onespace\n", 0, 0);
	c = ft_printf("%10.*d onespace\n", 0, 0);
	d = ft_printf("%10.*d onespace\n", 0, 0);
	printf("\nresultados por orden: %i, %i, %i, %i\n\n", a, b, c, d);
	return (0);
}
