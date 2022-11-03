/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:08:20 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/03 18:46:06 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int a;
    int b;
    
    a = ft_printf("%1.x, %1.x, %1.x, %1.x, %1.x, %1.x, %1.x, %1.x, %1.x, %1.x onespace\n", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX);
	b = printf("%1.x, %1.x, %1.x, %1.x, %1.x, %1.x, %1.x, %1.x, %1.x, %1.x onespace\n", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX);

	printf("\nft_printf: %i, printf: %i\n\n", a, b);


    //"!%#48.2x!" 664630336
    return (0);
}
