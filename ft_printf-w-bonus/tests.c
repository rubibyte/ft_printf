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
	printf("\n");

	a = ft_printf("% .5d onespace\n", -0);
	b = printf("% .5d onespace\n", -0);
	printf("\nreturns\nprintf: %i\nft_printf: %i\n\n\n", b, a);

	a = ft_printf("% .5d onespace\n", 567);
	b = printf("% .5d onespace\n", 567);
	printf("\nreturns\nprintf: %i\nft_printf: %i\n\n\n", b, a);

	a = ft_printf("% .5d onespace\n", -987);
	b = printf("% .5d onespace\n", -987);
	printf("\nreturns\nprintf: %i\nft_printf: %i\n\n\n", b, a);
/////////////
	a = ft_printf("% 5.10d onespace\n", -0);
	b = printf("% 5.10d onespace\n", -0);
	printf("\nreturns\nprintf: %i\nft_printf: %i\n\n\n", b, a);

	a = ft_printf("% 5.10d onespace\n", 567);
	b = printf("% 5.10d onespace\n", 567);
	printf("\nreturns\nprintf: %i\nft_printf: %i\n\n\n", b, a);

	a = ft_printf("% 5.10d onespace\n", 987);
	b = printf("% 5.10d onespace\n", 987);
	printf("\nreturns\nprintf: %i\nft_printf: %i\n\n\n", b, a);
////////////
	a = ft_printf("% 10.5d onespace\n", -0);
	b = printf("% 10.5d onespace\n", -0);
	printf("\nreturns\nprintf: %i\nft_printf: %i\n\n\n", b, a);

	a = ft_printf("% 10.5d onespace\n", 567);
	b = printf("% 10.5d onespace\n", 567);
	printf("\nreturns\nprintf: %i\nft_printf: %i\n\n\n", b, a);

	a = ft_printf("% 10.5d onespace\n", 987);
	b = printf("% 10.5d onespace\n", 987);
	printf("\nreturns\nprintf: %i\nft_printf: %i\n\n\n", b, a);
///////////////
	a = ft_printf("% .d onespace\n", -0);
	b = printf("% .d onespace\n", -0);
	printf("\nreturns\nprintf: %i\nft_printf: %i\n\n\n", b, a);

	a = ft_printf("% .5d onespace\n", -0);
	b = printf("% .5d onespace\n", -0);
	printf("\nreturns\nprintf: %i\nft_printf: %i\n\n\n", b, a);

	a = ft_printf("% 6.3d onespace\n", -8567);
	b = printf("% 6.3d onespace\n", -8567);
	printf("\nreturns\nprintf: %i\nft_printf: %i\n\n\n", b, a);
		
	return (0);
}
