/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 23:19:35 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/10/05 20:10:24 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

#include <stdio.h>

/*int	ft_printf(const char *str, ...)
{
	%#p
*/
int	main(void)
{
	char	a;
	char	*ptr;

	a = 'h';
	ptr = &a;

	printf("%p", ptr);
	printf("\n");
//	ft_printf_void_ptr_hex(ptr);
	printf("%d, %i\n", 10.2, 10.2);
	return (0);
}
