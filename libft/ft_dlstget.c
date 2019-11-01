#include "libft.h"

void			*ft_dlstget(t_dlist *lst, const void *data,
		int (*equ)(const void*, const void*))
{
	t_element	*elm;

	elm = lst->head;
	while (elm != NULL)
	{
		if (equ(data, elm->content) == 1)
			return (elm->content);
		elm = elm->next;
	}
	return (NULL);
}
