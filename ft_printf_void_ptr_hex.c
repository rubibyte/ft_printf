/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_void_ptr_hex.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:21:02 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/10/13 00:25:15 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

/*static int	ft_printf_hex_long(size_t n)
{
	char	*hex_low;
	char	c;
	int		n_char_wr;

	hex_low = ft_strdup("0123456789abcdef");
	if (n <= 16)
	{
		c = hex_low[n];
		n_char_wr = (int)write(1, &c, 1);
		free(hex_low);
		if (n_char_wr < 0)
			return (n_char_wr);
	}
	else
	{
		ft_printf_hex_long(n / 16);
		ft_printf_hex_long(n % 16);
	}
	return (0);
}*/

static size_t	ft_nbrlen_base(long n, char *base)
{
	size_t	size;

	if (n == 0)
		return (1);
	size = 0;
//	if (n < 0)
//		size++; not necessary in when using unsigned but don't delete to be reliable
	while (n)
	{
		size++;
		n /= ft_strlen(base);
	}
	return (size);
}


static char	*ft_lgtoa_base(size_t n, char *base)
{
	char 	*num_str;
	size_t	len;

	len = ft_nbrlen_base(n, base);
	num_str = (char *)malloc(len * sizeof(char) + 1);
	if (!num_str)
		return (NULL);
	num_str[len] = '\0';
	while (n)
	{
		--len;
		num_str[len] = base[n % ft_strlen(base)];
		n /= ft_strlen(base);
	}
	return (num_str);
}



int	ft_printf_void_ptr_hex(void *ptr)
{
	//size_t	address;
	int		n_char_wr;
	char	*num_str;
	int		temp_n;

	//address = (size_t)ptr;
	n_char_wr = (int)write(1, "0x", 2);
	if (n_char_wr < 0)
		return (n_char_wr);
	//n_char_wr = ft_printf_hex_long((size_t)ptr);
	num_str = ft_lgtoa_base((size_t)ptr, "0123456789abcdef");
	temp_n = (int)write(1, num_str, ft_strlen(num_str));
	if (temp_n < 0)
		return (temp_n);
	free(num_str);
	num_str = NULL;
	n_char_wr += temp_n;
	return (n_char_wr);
}
