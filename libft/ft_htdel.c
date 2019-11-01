#include "libft.h"

void	ft_htdel(t_hashtable **ht, void (*del)(void*))
{
	size_t  i;

	i = 0;
	while (i < (*ht)->size)
	{
		if (*((*ht)->entries + i))
			ft_htentrydel((*ht)->entries + i, del);
		i++;
	}
	free((*ht)->entries);
	ft_memdel((void**)ht);
}
