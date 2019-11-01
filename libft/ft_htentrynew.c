#include "libft.h"

t_htentry		*ft_htentrynew(const char *key, const void *content)
{
	t_htentry	*entry;

	entry = (t_htentry*)ft_memalloc(sizeof(t_htentry));
	if (entry != NULL)
	{
		entry->key = ft_strdup(key);
		if (entry->key != NULL)
			entry->content = (void*)content;
		else
			ft_memdel((void**)&entry);
	}
	return (entry);
}
