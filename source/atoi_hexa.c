#include "fdf.h"
\
int	skip(char *str)
{
	size_t	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
}

int	get_nb(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] && base[i] != c)
		i++;
	return (i);
}

int	atoi_hexa(char *str)
{
	long int	res;
	int			signe;
	char		*base;

	base = "0123456789ABCDEF";
	res = 0;
	signe = 1;
	str += skip((char *)str);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signe *= -1;
		str++;
	}
	while ((*str >= '0' && *str <= '9') || (*str >= 'A' && *str <= 'F'))
	{
		res = (res * 16) + get_nb(*str, base);
		str++;
	}
	return (res * signe);
}
