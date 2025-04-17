/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:50:56 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/17 17:38:08 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

#ifndef size_t
# define size_t unsigned long long int
#endif

char	*ft_strchr(const char *s, int b);
char	*ft_strjoin(char *s1, char *s2);
char	*isolate_line(char *line, char *buffer);