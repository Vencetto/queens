/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:06:15 by vzomber           #+#    #+#             */
/*   Updated: 2017/12/01 21:14:28 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <unistd.h>
# include <wchar.h>

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef	struct		s_pack
{
	int				i;
	int				k;
	char			c;
	char			*s;
	char			**arr;
}					t_pack;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *stack, const char *ndl, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
intmax_t			ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(intmax_t n, int fd);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(intmax_t n);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t				ft_chars(char const *s, char c);
intmax_t			ft_len(intmax_t n, int base);
int					ft_abs(int n);
size_t				ft_wordnum(const char *s, char c);
char				*ft_itoa_base(intmax_t nb, int base);
char				*ft_uitoa_base(uintmax_t nb, int base);
void				ft_putnbr_m(intmax_t n);
void				ft_upletters(char *str);
uintmax_t			ft_ulen(uintmax_t n, int base);
void				ft_huge_mzfk(intmax_t nb);
void				ft_uputnbr_m(uintmax_t n);
int					ft_putunistr(wchar_t *s);
size_t				ft_unistrlen(wchar_t *s);
int					put_wchar(wchar_t c);
int					count_bytes(wchar_t c);
void				ft_uhuge_mzfk(uintmax_t nb);
void				*ft_memcpy_fwd(void *dst, const void *src, size_t n);
char				*ft_concat(char *s1, char *s2);
void				ft_arrfree(char **arr);
char				**ft_memforarr(char **arr, int x, int y);
int					ft_strisnumber(char *str);
char				*ft_strndup(const char *s1, int n);
int					ft_strcchr(const char *s, int c);
#endif
