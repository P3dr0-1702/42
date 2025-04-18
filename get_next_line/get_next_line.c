/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:50:07 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/18 11:09:50 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 64
#endif

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buffer[0] == '\0')
		{
			i = read(fd, buffer, BUFFER_SIZE);
			if (i <= 0)
				break ;
			buffer[i] = '\0';
		}
		if (ft_strchr(buffer, '\n'))
		{
			line = isolate_line(line, buffer);
			return (line);
		}
		line = ft_strjoin(line, buffer);
		buffer[0] = '\0';
	}
	return (line);
}
// int	main(void)
// {
// 	int	fd;
// 	int	i;
// 	char *line;

// 	i = 0;
// 	fd = open("text.txt", O_RDONLY);
// 	printf("%d\n", fd);
// 	while (i < 3)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 		i++;
// 	}
// }
// char	*isolate_line(char *line, char *buffer)
// {
// 	int		i;
// 	int		j;
// 	char	*temp;

// 	i = 0;
// 	j = -1;
// 	while (buffer[i] != '\0' && buffer[i] != '\n')
// 		i++;
// 	if (buffer[i] == '\n')
// 		i++;
// 	temp = malloc(i + 1);
// 	if (!temp)
// 		return (NULL);
// 	while (++j < i)
// 		temp[j] = buffer[j];
// 	temp[j] = '\0';
// 	j = 0;
// 	while (buffer[i] != '\0')
// 		buffer[j++] = buffer[i++];
// 	buffer[j] = '\0';
// 	line = ft_strjoin(line, temp);
// 	free(temp);
// 	return (line);
// }

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!str)
// 		return (0);
// 	while (str[i] != '\0')
// 		i++;
// 	return (i);
// }
// char	*ft_strjoin(char *s1, char *s2)
// {
// 	int		i;
// 	int		j;
// 	char	*joined;

// 	j = 0;
// 	i = 0;
// 	joined = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
// 	if (!joined)
// 		return (NULL);
// 	if (s1)
// 	{
// 		while (s1[i] != '\0')
// 		{
// 			joined[i] = s1[i];
// 			i++;
// 		}
// 	}
// 	while (s2[j] != '\0')
// 	{
// 		joined[i + j] = s2[j];
// 		j++;
// 	}
// 	joined[i + j] = '\0';
// 	free(s1);
// 	return (joined);
// }

// char	*ft_strchr(const char *s, int b)
// {
// 	int	i;

// 	i = 0;
// 	if (!s)
// 		return (NULL);
// 	if ((char)b == '\0')
// 		return ((char *)s + ft_strlen(s));
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == (char)b)
// 			return ((char *)s + i);
// 		i++;
// 	}
// 	return (NULL);
// }
