#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	*str;

	str = "hola";
	ft_printf("el número es: %30p\n", str);
	ft_printf("el numero es: %30x\n", str);
	ft_printf("el numero es: %30X\n", str);
	ft_printf("el numero es: %30d\n", str);
	ft_printf("el numero es: %30i\n", str);
	ft_printf("el número es: \%  %+30s\n\n", str);

	printf("el número es: %000000p\n", str);
	printf("el numero es: %30x\n", str);
	printf("el numero es: %30X\n", str);
	printf("el numero es: %30d\n", str);
	printf("el numero es: %30.*i\n", 12, 8976);
	printf("el número es: \%+ #0-+   0#-++-..30s iii\n", str);

	printf(" ft_strchr: %s\n ft_strrchr: %s\n char * 0: %s fin\n", ft_strchr("# +-0", 'k'), ft_strrchr("# +-0", 7), 0);

	if (ft_strchr("# +-0", '-'))
		printf("true\n");
	else 
		printf("false\n");
	printf("%serpiente\n", "holas");

	return (0);
}
