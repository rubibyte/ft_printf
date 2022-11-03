/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:08:20 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/03 13:45:05 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int a;
    int b;
    
    a = ft_printf(" % \n");
	printf("\n");
	b = printf("\nlaflkjsldkfjldksjf %  lkjljl;kj");
	printf("\nft_printf: %i, printf: %i\n\n", a, b);

    return (0);
}
