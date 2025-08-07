/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:53:07 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/07 13:52:21 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "limits.h"
# include "stdarg.h"
# include "stdbool.h"
# include "stdint.h"
# include "stdio.h"
# include "stdlib.h"
# include "unistd.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// libft functions
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *s);
void				ft_bzero(void *a, size_t i);
void				*ft_calloc(size_t nmemb, size_t size);
int					ft_isalnum(char a);
int					ft_isalpha(int a);
int					ft_isascii(int a);
int					ft_isdigit(int i);
int					ft_isprint(int a);
char				*ft_itoa(int n);
void				*ft_memchr(const void *a, int b, size_t c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t i);
void				*ft_memmove(void *dest, const void *src, size_t i);
void				*ft_memset(void *a, int c, size_t i);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *a, int b);
char				*ft_strdup(const char *src);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
unsigned int		ft_strlcat(char *dest, const char *src, size_t size);
unsigned int		ft_strlcpy(char *dest, const char *scr, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *str, const char *to_find, size_t n);
char				*ft_strrchr(const char *a, int b);
char				*ft_strtrim(const char *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_tolower(int a);
int					ft_toupper(int a);

void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
// libft functions end

int					ft_printf(const char *format, ...);
// use these to kick a int adress around to tally up the amout of printed chars
// these are necessary for printf
void				ft_printlhex(void *ptr, int *n);
void				ft_putlchar(char c, int *n);
void				ft_putlnbr_hex(unsigned int nb, int *n);
void				ft_putlnbr_hexlow(unsigned int nb, int *n);
void				ft_putlnbr(int nb, int *n);
void				ft_putlstr(char *str, int *n);
void				ft_putlunbr(unsigned int nb, int *n);

// same as before but without counting printed chars
void				ft_printhex(void *ptr);
void				ft_putchar(char c);
void				ft_putnbr_hex(unsigned int nb);
void				ft_putnbr_hexlow(unsigned int nb);

int					ft_count_words(char const *s, char c);
int					ft_strcmp(char *s1, char *s2);
void				i_wanna_break_free(char **array);
char				*ft_wordcpy(const char **s, char c);
void				ft_putstr(char *str);

int					randomizer(void);

// get next line
char				*ft_strchr(const char *s, int b);
char				*gnl_strjoin(char *s1, char *s2);
char				*isolate_line(char *line, char *buffer);
size_t				ft_strlen(const char *str);
char				*get_next_line(int fd);

#endif
