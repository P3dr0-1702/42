/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:53:07 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/10 11:58:37 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

int				ft_atoi(const char *str);
void			ft_bzero(void *a, size_t i);
void			*ft_calloc(size_t nmemb, size_t size);
int				ft_isalnum(char a);
int				ft_isalpha(char a);
int				ft_isascii(char a);
int				ft_isdigit(int i);
int				ft_isprint(char a);
char			*ft_itoa(int n);
void			*ft_memchr(const void *a, int b, size_t c);
int				ft_memcmp(const void *s1, const void *s2);
void			*memcpy(void *dest, const void *src, size_t i);
void			*ft_memmove(void *dest, const void *src, size_t i);
void			*ft_memset(void *a, int c, size_t i);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
char			**ft_split(char const *s, char c);
int				ft_str_is_alpha(char *str);
int				ft_str_is_printable(char *str);
char			*ft_strchr(const char *a, int b);
char			*ft_strdup(const char *src);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
unsigned int	ft_strlcat(char *dest, const char *src, size_t size);
unsigned int	ft_strlcpy(char *dest, const char *scr, size_t size);
size_t			ft_strlen(const char *str);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(char *s1, char *s2, size_t n);
char			*ft_strnstr(char *str, char *to_find, size_t n);
char			*strrchr(const char *a, int b);
char			*ft_strtrim(const char *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_tolower(int a);
int				ft_toupper(int a);
