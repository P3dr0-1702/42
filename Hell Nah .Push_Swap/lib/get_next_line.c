/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:50:07 by pfreire-          #+#    #+#             */
/*   Updated: 2025/05/15 13:55:30 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
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
			return (isolate_line(line, buffer));
		line = gnl_strjoin(line, buffer);
		buffer[0] = '\0';
	}
	if (i < 0)
		return (free(line), NULL);
	return (line);
}
// int	main(void)
// {
// 	int	fd;
// 	int	i;
// 	char *line;

// 	i = 0;
// 	fd = open("one_line_no_nl.txt", O_RDONLY);
// 	printf("%d\n", fd);
// 	while (i < 2)
// 	{
// 		line = get_next_line(1);
// 		printf("%s", line);
// 		free(line);
// 		i++;
// 	}
// }