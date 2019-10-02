/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 14:38:37 by ybahlaou          #+#    #+#             */
/*   Updated: 2019/04/28 00:56:01 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words_count(char const *str, char c)
{
	int	count;
	int	can_count;
	int	is_spliter;

	count = 0;
	can_count = 1;
	while (*str)
	{
		is_spliter = *str == c;
		if (is_spliter)
			can_count = 1;
		if (!is_spliter && can_count)
		{
			count++;
			can_count = 0;
		}
		str++;
	}
	return (count);
}

static char	*ft_copy(char const **src, char c)
{
	char	*str;
	int		len;
	int		i;

	while (**src == c && **src)
		(*src)++;
	len = 0;
	str = (char*)*src;
	while (*(str + len) != c && *(str + len))
		len++;
	if (!(str = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(str + i) = **src;
		(*src)++;
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

static void	ft_freetab(char **tab)
{
	int		i;
	char	*row;

	i = 0;
	while ((row = *(tab + i)) != NULL)
	{
		free(row);
		i++;
	}
	free(tab);
}

char		**ft_strsplit(char const *str, char c)
{
	char	**array;
	int		i;
	int		size;

	size = ft_words_count(str, c);
	array = (char**)ft_memalloc(sizeof(char*) * (size + 1));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		*(array + i) = ft_copy(&str, c);
		if (*(array + i) == NULL)
		{
			ft_freetab(array);
			return (NULL);
		}
		i++;
	}
	*(array + i) = NULL;
	return (array);
}
