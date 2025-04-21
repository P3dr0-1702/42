/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:50:56 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/21 14:54:26 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_strchr(const char *s, int b);
char	*ft_strjoin(char *s1, char *s2);
char	*isolate_line(char *line, char *buffer);
size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
// char **found_line(char *buffer, char *line);