#include "libft.h"

long	ft_atol(const char *str)
{
	int			i;
	int			sign;
	long long	nbr;

	i = 0;
	sign = 0;
	nbr = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		nbr = nbr * 10;
		nbr = nbr + (str[i] - 48);
		i++;
	}
	if (sign == -1)
		return (-nbr);
	return (nbr);
}
