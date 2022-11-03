/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:39:00 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/03 13:09:55 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

/*int	main(void)
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
}*/


int	main(void)
{
	int	a;
	int	b;

	a = ft_printf("This is a simple test.");
	printf("\n");
	b = printf("This is a simple test.");
	printf("\nft_printf: %i, printf: %i\n\n", a, b);

	a = ft_printf("This is a simple test.\nSecond sentence.\n");
	printf("\n");
	b = printf("This is a simple test.\nSecond sentence.\n");
	printf("\nft_printf: %i, printf: %i\n\n", a, b);


	a = ft_printf("");
	printf("\n");
	b = printf("");
	printf("\nft_printf: %i, printf: %i\n\n", a, b);

	a = ft_printf("\n");
	printf("\n");
	b = printf("\n");
	printf("\nft_printf: %i, printf: %i\n\n", a, b);

	a = ft_printf("%s", "abc");
	printf("\n");
	b = printf("%s", "abc");
	printf("\nft_printf: %i, printf: %i\n\n", a, b);

	a = ft_printf("111%s333", "222");
	printf("\n");
	b = printf("111%s333", "222");
	printf("\nft_printf: %i, printf: %i\n\n", a, b);

	a = ft_printf("%s333", "222");
	printf("\n");
	b = printf("%s333", "222");
	printf("\nft_printf: %i, printf: %i\n\n", a, b);

	a = ft_printf("111%s", "222");
	printf("\n");
	b = printf("111%s", "222");
	printf("\nft_printf: %i, printf: %i\n\n", a, b);

	a = ft_printf("{%s}", 0);
	printf("\n");
	b = printf("{%s}", 0);
	printf("\nft_printf: %i, printf: %i\n\n", a, b);

	a = ft_printf("{%s}", "");
	printf("\n");
	b = printf("{%s}", "");
	printf("\nft_printf: %i, printf: %i\n\n", a, b);

	a = ft_printf("111%s333%s555", "222", "444");
	printf("\n");
	b = printf("111%s333%s555", "222", "444");
	printf("\nft_printf: %i, printf: %i\n\n", a, b);

	a = ft_printf("111%s333%s555%saaa%sccc", "222", "444", "666", "bbb");
	printf("\n");
	b = printf("111%s333%s555%saaa%sccc", "222", "444", "666", "bbb");
	printf("\nft_printf: %i, printf: %i\n\n", a, b);

	a = ft_printf("%s%s%s%s%s", "1", "2", "3", "4", "5");
	printf("\n");
	b = printf("%s%s%s%s%s", "1", "2", "3", "4", "5");
	printf("\nft_printf: %i, printf: %i\n\n", a, b);

	a = ft_printf("%d", 42);
	printf("\n");
	b = printf("%d", 42);
	printf("\nft_printf: %i, printf: %i\n\n", a, b);

	a = ft_printf("%d", -42);
	printf("\n");
	b = printf("%d", -42);
	printf("\nft_printf: %i, printf: %i\n\n", a, b);

	a = ft_printf("before %d after", 42);
	printf("\n");
	b = printf("before %d after", 42);
	printf("\nft_printf: %i, printf: %i\n\n", a, b);

	a = ft_printf("%d%d%d%d%d", 1, -2, 3, -4, 5);
	printf("\n");
	b = printf("%d%d%d%d%d", 1, -2, 3, -4, 5);
	printf("\nft_printf: %i, printf: %i\n\n", a, b);

	a = ft_printf("a%db%dc%dd", 1, -2, 3);
	printf("\n");
	b = printf("a%db%dc%dd", 1, -2, 3);
	printf("\nft_printf: %i, printf: %i\n\n", a, b);

	a = ft_printf("%d", INT_MAX);
	printf("\n");
	b = printf("%d", INT_MAX);
	printf("\nft_printf: %i, printf: %i\n\n", a, b);

	a = ft_printf("%d", INT_MIN);
	printf("\n");
	b = printf("%d", INT_MIN);
	printf("\nft_printf: %i, printf: %i\n\n", a, b);

	//a = ft_printf("%p", &strlen);
	//printf("\n");
	//b = printf("%p", &strlen);
	//printf("\nft_printf: %i, printf: %i\n\n", a, b);

	a = ft_printf("%p", 0);
	printf("\n");
	b = printf("%p", 0);
	printf("\nft_printf: %i, printf: %i\n\n", a, b);

	a = ft_printf("%%");
	printf("\n");
	b = printf("%%");
	printf("\nft_printf: %i, printf: %i\n\n", a, b);

	a = ft_printf("aa%%bb");
	printf("\n");
	b = printf("aa%%bb");
	printf("\nft_printf: %i, printf: %i\n\n", a, b);

	a = ft_printf("%%%%%%%%%%");
	printf("\n");
	b = printf("%%%%%%%%%%");
	printf("\nft_printf: %i, printf: %i\n\n", a, b);

	a = ft_printf(".%%.%%.%%.%%.%%.%%.%%.%%.");
	printf("\n");
	b = printf(".%%.%%.%%.%%.%%.%%.%%.%%.");
	printf("\nft_printf: %i, printf: %i\n\n", a, b);

	a = ft_printf("%");
	printf("\n");
	b = printf("%");
	printf("\nft_printf: %i, printf: %i\n\n", a, b);

	a = ft_printf("{% %}");
	printf("\n");
	b = printf("{% %}");
	printf("\nft_printf: %i, printf: %i\n\n", a, b);

	a = ft_printf("%s%p%d%d%p%s%p%p%s", "a", &free, 1, 2, &malloc, "b", &free, &malloc, "c");
	printf("\n");
	b = printf("%s%p%d%d%p%s%p%p%s", "a", &free, 1, 2, &malloc, "b", &free, &malloc, "c");
	printf("\nft_printf: %i, printf: %i\n\n", a, b);

	a = ft_printf("%i", 42);
	printf("\n");
	b = printf("%i", 42);
	printf("\nft_printf: %i, printf: %i\n\n", a, b);
	
	a = ft_printf("%i", -42);
	printf("\n");
	b = printf("%i", -42);
	printf("\nft_printf: %i, printf: %i\n\n", a, b);

	a = ft_printf("before %i after", 42);
	printf("\n");
	b = printf("before %i after", 42);
	printf("\nft_printf: %i, printf: %i\n\n", a, b);

	a = ft_printf("%i%i%i%i%i", 1, -2, 3, -4, 5);
	printf("\n");
	b = printf("%i%i%i%i%i", 1, -2, 3, -4, 5);
	printf("\nft_printf: %i, printf: %i\n\n", a, b);

	return (0);
}


