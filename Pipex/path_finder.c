/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:43:50 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/11 15:48:17 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char **pathfinder(char **env)
{
	char **paths;
	char *str;
	int i;
	i = 0;
	while(ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	str = ft_strdup(env[i] + 5);
	paths = ft_split(str, ':');
	free(str);
	return(paths);
}

bool command_exist(char *command, char **path)
{
	bool found = false;
	int i = 0;
	int fd = 0;
	while(path[i])
	{
		fd = open(ft_strjoin(ft_strjoin(path[i],"/"), command), O_RDONLY);
		if(fd > 0)
		{
			found = true;
		}
		i++;
	}
	return(found);
}
