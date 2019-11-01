#include "libft.h"

t_element	*ft_elemnew(const void *content)
{
	t_element	*elm;

	elm = (t_element*)ft_memalloc(sizeof(t_element));
	if (!elm)
		return (NULL);
	elm->content = (void*)content;
	return (elm);
}
