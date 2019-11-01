#include "libft.h"

void					ft_htinsert(t_hashtable *ht, const t_htentry *entry)
{
	size_t	index;
	size_t	start;

	index = compute_hash(entry->key) % ht->size;
	start = index;
	if (ht->entries[index] == NULL)
	{
		ht->entries[index] = (t_htentry*)entry;
		return ;
	}
	while (1)
	{
		if (ht->entries[index] == NULL)
			break ;
		index++;
		if (index == start)
			return ;
		if (index == ht->size)
			index = 0;
	}
	ht->entries[index] = (t_htentry*)entry;
}
