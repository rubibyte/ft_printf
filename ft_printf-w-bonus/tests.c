/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:39:00 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/03 01:22:41 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	a;
	int	b;
//resolver que espacio y signo sean parte de los caracteres de width y
//que no lo sean de precision. 
//Durante el proceso evitar que genere conflicto una cosa con la otra
	
	a = ft_printf("%+.5d onespace\n", -0);
	b = printf("%+.5d onespace\n", -0);

	printf("\n\nreturns\nprintf: %i\nft_printf: %i", b, a);

	
	
	return (0);
}
