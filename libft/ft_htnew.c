#include "libft.h"

t_hashtable		*ft_htnew(size_t size)
{
	t_hashtable *ht;

	if (size == 0)
		return (NULL);
	ht = (t_hashtable*)ft_memalloc(sizeof(t_hashtable));
	if (ht != NULL)
	{
		ht->size = size;
		ht->entries = (t_htentry**)ft_memalloc(sizeof(t_htentry*) * size);
		if (ht->entries == NULL)
			ft_memdel((void**)&ht);
	}
	return (ht);
}
