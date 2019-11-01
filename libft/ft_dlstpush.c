#include "libft.h"

void	ft_dlstpush(t_dlist *lst, t_element *elm)
{
	lst->size++;
	if (!lst->head)
	{
		lst->head = elm;
		lst->tail = elm;
		return ;
	}
	lst->tail->next = elm;
	elm->prev = lst->tail;
	lst->tail = elm;
}
