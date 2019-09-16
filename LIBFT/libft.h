/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 14:28:25 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/03/04 15:54:51 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "./ft_printf/ft_printf.h"

/*
** Struct t_list
*/

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** Functions from string.h (includes size_t as does stddef.h)
** or to do with strings
*/

int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strdup(const char *src);
char				*ft_strndup(const char *src, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				*ft_memset(void *str, int c, size_t n);
void				*ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void				*ft_memchr(const void *str, int c, size_t n);
void				*ft_memmove(void *s1, const void *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
char				*ft_strchr(const char *ar, int n);
char				*ft_strrchr(const char *ar, int n);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle, \
					size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ar);
char				*ft_strnew(size_t size);
void				ft_strdel(char **ar);
void				ft_strclr(char *ar);
void				ft_striter(char *ar, void (*f)(char *));
void				ft_striteri(char *ar, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *ar, char (*f)(char));
char				*ft_strmapi(char const *ar, char (*f)(unsigned int, char));
int					ft_strequ(const char *str1, const char *str2);
int					ft_strnequ(const char *str1, const char *str2, size_t n);
char				*ft_strsub(const char *str1, unsigned int start, \
					size_t len);
char				*ft_strjoin(char const *str1, char const *str2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				ft_putendl(const char *s);
void				ft_putendl_fd(const char *s, int fd);

/*
** Functions from stdlib.h
*/

int					ft_atoi(const char *str);

/*
** Functions from ctype.h
*/

int					ft_isalpha(int n);
int					ft_isdigit(int n);
int					ft_isalnum(int n);
int					ft_isascii(int n);
int					ft_isprint(int n);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
** Functions from stdio.h
*/

void				ft_putchar(char c);

/*
** Own creations
*/

void				ft_putstr(const char *ar);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *ar, int fd);
void				ft_putnbr(long long int n);
void				ft_put_u_long(unsigned long long int n);
void				ft_putnbr_fd(int n, int fd);
size_t				ft_char_ignore(const char *ar, char c);
size_t				ft_countwords(const char *ar, char c);
size_t				ft_nbrlen(long long int n);
char				*ft_itoa(int n);
int					ft_iswhitespace(char c);
char				**ft_splithelp(char const *s, char c, size_t y, size_t x);
unsigned			ft_count_nline(const char *s);
int					ft_countbits(unsigned long long int n);
unsigned long long	xy_power(int x, int y);
char				*ft_itoabase(long long value, int base);
char				*ft_strrev(char *str);
size_t				ft_strlchr(char *s, char c, size_t len);
int					ft_max(int a, int b);
int					ft_min(int a, int b);

/*
** Linked lists
*/

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del) (void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
