/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:43:50 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/18 15:40:37 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**pathfinder(char **env)
{
	char	**paths;
	char	*str;
	int		i;

	i = 0;
	if (!env)
		return (NULL);
	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	if (!env[i])
		return (NULL);
	str = ft_strdup(env[i] + 5);
	paths = ft_split(str, ':');
	free(str);
	return (paths);
}

int	command_exist(char *command, char **path)
{
	int		i;
	int		fd;
	char	*str;
	char	*str2;

	i = 0;
	fd = 0;
	while (path[i] != NULL)
	{
		str2 = ft_strjoin(path[i], "/");
		str = ft_strjoin(str2, command);
		fd = access(str, F_OK);
		if (fd == 0)
		{
			free(str);
			free(str2);
			return (i);
		}
		i++;
		free(str);
		free(str2);
	}
	return (-1);
}
