/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:51:38 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/04 18:30:59 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int	a, b, c, d;

	a = printf("%#030.*x onespace\n", 10, 834756);
	b = printf("%#030.*x onespace\n", 10, 834756);
	c = ft_printf("%#030.*x onespace\n", 10, 834756);
	d = ft_printf("%#030.*x onespace\n", 10, 834756);
	printf("\nresultados por orden: %i, %i, %i, %i\n\n", a, b, c, d);

	a = printf("%#030.*x onespace\n", 1, -423);
	b = printf("%#030.*x onespace\n", 1, -423);
	c = ft_printf("%#030.*x onespace\n", 1, -423);
	d = ft_printf("%#030.*x onespace\n", 1, -423);
	printf("\nresultados por orden: %i, %i, %i, %i\n\n", a, b, c, d);
	return (0);
}
