#include "libft.h"

size_t		ft_getindex(t_hashtable *ht, const char *key)
{
	size_t 	index;

	index = compute_hash(key) % ht->size;
	return (index);
}
