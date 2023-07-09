/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:00:36 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/09 20:58:11 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <bsd/bsd.h>
# include <ctype.h>
# include <errno.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

char				*ft_itoa(int n);
int					ft_atoi(const char *nptr);
int					ft_isspace(int c);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isquote(char c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_skip_whitespace(char **str);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dest, const char *src);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *s1, char *s2, int n);
char				*ft_strndup(const char *str, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char const *s1, char const *set);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *s);
void				ft_bzero(void *s, size_t n);
void				ft_putendl_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(void *content);
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
int					ft_lstsize(t_list *lst);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_is_input_only_whitespaces(char *str);
int					ft_is_input_quotes_and_whitespaces(char *str);
/* ft_printf */
int					ft_printf(const char *s, ...);

/* get_next_line */
char				*get_next_line(int fd);
size_t				ft_strlen_gnl(char *s);
char				*ft_strjoin_gnl(char *s1, char *s2);
int					stash_organizer(char *stash);
#endif
