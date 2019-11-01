#include "libft.h"

t_dlist	*ft_dlstnew(void)
{
	return ((t_dlist*)ft_memalloc(sizeof(t_dlist)));
}
