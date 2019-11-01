#include "libft.h"

void	ft_dlstdel(t_dlist **lst, void (*del)(void*))
{
	t_element	*current;
	t_element	*to_del;

	current = (*lst)->head;
	while (!current)
	{
		to_del = current;
		current = current->next;
		del(to_del->content);
		ft_memdel((void**)&to_del);
	}
	ft_memdel((void**)lst);
}
