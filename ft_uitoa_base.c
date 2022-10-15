



#include "libft/libft.h"


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


char	*ft_uitoa_base(unsigned int n, char *base)
{
	char	*num_str;
	size_t	len;

	if (n < 0)
		ft_uitoa_base(4294967296 + n, base);
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
