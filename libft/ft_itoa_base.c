/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 01:35:46 by ybahlaou          #+#    #+#             */
/*   Updated: 2019/07/10 01:54:03 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen_base(int nbr, int base)
{
	int	count;

	count = 1;
	while ((nbr /= base) != 0)
		count++;
	return (count);
}

static void	ft_setvalue(char *str, int nbr, int base, const char *strbase)
{
	if (nbr >= base)
		ft_setvalue(str - 1, nbr / base, base, strbase);
	*str = *(strbase + (nbr % base));
}

char		*ft_itoa_base(int nbr, int base)
{
	char	*str;
	int		len;

	if (base == 10)
		return (ft_itoa(nbr));
	len = ft_nbrlen_base(nbr, base);
	str = ft_strnew((size_t)len);
	if (str != NULL)
		ft_setvalue(str + len - 1, nbr, base, "0123456789abcdef");
	return (str);
}
