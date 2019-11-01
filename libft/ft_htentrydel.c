#include "libft.h"

void	ft_htentrydel(t_htentry **entry, void (*del)(void*))
{
	if (entry == NULL || *entry == NULL)
		return ;
	ft_strdel(&(*entry)->key);
	del((*entry)->content);
	ft_memdel((void**)entry);
}
