/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 11:49:33 by ybahlaou          #+#    #+#             */
/*   Updated: 2019/10/07 06:12:52 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define MAX(a, b) (a > b ? a : b)
# define MIN(a, b) (a < b ? a : b)
# define ABS(a) (a < 0 ? -a : a)

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <wchar.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_btree
{
	void			*content;
	size_t			content_size;
	struct s_btree	*left;
	struct s_btree	*right;
}				t_btree;

typedef struct	s_element
{
	void				*content;
	struct s_element	*next;
	struct s_element	*prev;
}				t_element;

typedef struct	s_dlist
{
	t_element	*head;
	t_element	*tail;
	size_t		size;
}				t_dlist;

typedef struct	s_htentry
{
	char		*key;
	void		*content;
}				t_htentry;

typedef struct	s_hashtable
{
	t_htentry	**entries;
	size_t		size;
}				t_hashtable;

/*
**	std
*/

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *b, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_isupper(int c);
int				ft_islower(int c);
int				ft_isspace(int c);
int				ft_isblank(int c);
int				ft_atoi(const char *str);
char			*ft_itoa(int nbr);
long			ft_atol(const char *str);
char			*ft_itoa_base(int nbr, int base);
int				ft_islong(const char *str, char c);
int				ft_isulong(const char *str, char c);

/*
** input/output
*/

void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(const char *s);
void			ft_putnbr(int n);
void			ft_putlnbr(long n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putlnbr_fd(long n, int fd);
void			ft_putwchar(wchar_t c);
void			ft_putwstr(const wchar_t *str);

/*
** strings
*/

size_t			ft_strlen(const char *str);
size_t			ft_strnlen(const char *str, size_t maxlen);
size_t			ft_strclen(const char *str, char c);
char			*ft_strdup(const char *src);
char			*ft_strndup(const char *src, size_t n);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *str, const char *to_find);
char			*ft_strnstr(const char *str, const char *to_find, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strpbrk(const char *str, const char *charset);
char			*ft_strrev(char *str);
int				ft_strstartswith(const char *str, const char *sub);
int				ft_strendswith(const char *str, const char *sub);
ssize_t			ft_indexof(const char *str, char c);
ssize_t			ft_lastindexof(const char *str, char c);
size_t			ft_countof(const char *str, char c);
char			*ft_strreplace(const char *str,
						const char *old, const char *new);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			*ft_strctrim(const char *s, char c);
char			**ft_strsplit(char const *s, char c);
size_t			ft_wcslen(const wchar_t *str);
wchar_t			*ft_wcsdup(const wchar_t *src);
char			*ft_strtoupper(const char *str);
char			*ft_strtolower(const char *str);

/*
** linked list
*/

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstsort(t_list *lst, int (*cmp)(t_list*, t_list*));
void			ft_lstrev(t_list **lst);
t_list			*ft_lstget(t_list *lst, size_t index);
size_t			ft_lstsize(t_list *lst);
void			ft_lstaddend(t_list **lst, t_list *elm);
t_list			*ft_lstfind(t_list *lst, void *data, int (*cmp)(void*, void*));
void			ft_lstremoveat(t_list **lst,
					void (*del)(void*, size_t), size_t i);

/*
** doubly linked list
*/

t_dlist			*ft_dlstnew(void);
void			*ft_dlstget(t_dlist *lst, const void *data,
					int (*equ)(const void*, const void*));
void			ft_dlstdel(t_dlist **lst, void (*del)(void*));
void			ft_dlstpush(t_dlist *lst, t_element *elm);
t_element		*ft_elemnew(const void *content);

/*
** binary tree
*/

t_btree			*ft_btreenew(const void *content, size_t content_size);
void			ft_btreeadd(t_btree **root, t_btree *elm,
				int (*cmp)(t_btree *elm, t_btree *side));
t_btree			*ft_btreefind(t_btree *root, void *to_find,
					int (*cmp)(void*, void*));
void			ft_btreedel(t_btree **root, void (*del)(void*, size_t));
void			ft_btreepreorder(t_btree *root, void (*ft)(t_btree*));
void			ft_btreeinorder(t_btree *root, void (*ft)(t_btree*));
void			ft_btreepostorder(t_btree *root, void (*ft)(t_btree*));

/*
** hashtable
*/

t_hashtable		*ft_htnew(size_t size);
void			ft_htdel(t_hashtable **ht, void (*del)(void*));
void			*ft_htget(t_hashtable *ht, const char *key);
void			ft_htinsert(t_hashtable *ht, const t_htentry *entry);
t_htentry		*ft_htentrynew(const char *key, const void *content);
void			ft_htentrydel(t_htentry **entry, void (*del)(void*));
int				equ(const void *target, const void *current);
size_t			ft_getindex(t_hashtable *ht, const char *key);
size_t			compute_hash(const char *key);

#endif
