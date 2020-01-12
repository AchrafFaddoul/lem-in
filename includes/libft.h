/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <smouzdah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 11:20:27 by afaddoul          #+#    #+#             */
/*   Updated: 2020/01/12 12:27:59 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct			s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}						t_list;

typedef struct			s_element
{
	void				*content;
	struct s_element	*next;
	struct s_element	*prev;
}						t_element;

typedef struct			s_dlist
{
	t_element			*head;
	t_element			*tail;
	size_t				size;
}						t_dlist;

typedef struct			s_htentry
{
	char				*key;
	int					flow;
	void				*content;
}						t_htentry;

typedef struct			s_hashtable
{
	t_htentry			**entries;
	size_t				size;
}						t_hashtable;

void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memccpy(void *dst, const void *src, int c,
		size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
size_t					ft_strlen(const char *s);
char					*ft_strdup(const char *s1);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strncpy(char *dst, const char *src, size_t len);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strncat(char *s1, const char *s2, size_t n);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(const char *haystack, const char *needle);
char					*ft_strnstr(const char *haystack, const char *needle,
		size_t len);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_atoi(const char *str);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char (*f) (char));
char					*ft_strmapi(char const *s,
		char (*f) (unsigned int, char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strsub(char const *s, unsigned int start,
		size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
void					ft_putchar(char c);
void					ft_putstr(char const *s);
void					ft_putendl(char const *s);
void					ft_putnbr(long long n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
char					*ft_strtrim(char const *s);
char					**ft_strsplit(char const *s, char c);
int						ft_word_counter(const char *s, char c);
char					*ft_itoa(unsigned long long n);
char					*ft_strrev(char *str);
int						ft_nb_len(long long n);
t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdelone(t_list **alst,
		void (*del)(void *, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char					*ft_strupcase(char *str);
char					*ft_strlowcase(char *str);
void					ft_swap(int *a, int *b);
int						ft_unsigned_nb_len(unsigned long long n);
long					ft_atol(const char *str);
size_t					ft_countof(const char *str, char c);
void					ft_dlstdel(t_dlist **lst, void (*del)(void*));
void					*ft_dlstget(t_dlist *lst, const void *data,
		int (*equ)(const void*, const void*));
t_dlist					*ft_dlstnew(void);
void					ft_dlstpush(t_dlist *lst, t_element *elm);
t_element				*ft_elemnew(const void *content);
size_t					ft_getindex(t_hashtable *ht, const char *key);
size_t					compute_hash(const char *key);
void					*ft_htget(t_hashtable *ht, const char *key);
size_t					ft_strclen(const char *str, char c);
char					*ft_strndup(const char *src, size_t n);
int						ft_isulong(const char *str, char c);
t_hashtable				*ft_htnew(size_t size);
t_htentry				*ft_htentrynew(const char *key, const void *content);
long long				ft_htinsert(t_hashtable *ht, const t_htentry *entry);
void					ft_htdel(t_hashtable **ht, void (*del)(void*));
void					ft_htentrydel(t_htentry **entry, void (*del)(void*));

#endif
