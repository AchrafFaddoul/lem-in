#include "libft.h"
#include <stdio.h>

void			*ft_dlstget(t_dlist *lst, const void *data,
		int (*equ)(const void*, const void*))
{
	t_element	*front;
	t_element	*rear;

	front = lst->head;
	rear = lst->tail;
	while (front != NULL && rear != NULL)
	{
		if (equ(data, front->content) == 1)
			return (front->content);
		if (equ(data, rear->content) == 1)
			return (rear->content);
		front = front->next;
		rear = rear->prev;
	}
	return (NULL);
}
