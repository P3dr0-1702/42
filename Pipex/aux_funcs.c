/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:43:50 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/19 22:02:16 by pfreire-         ###   ########.fr       */
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
	if (!str)
		return (NULL);
	paths = ft_split(str, ':');
	if (!paths)
		return (NULL);
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

void	free_pipex(t_pipex *pipex)
{
	if (pipex->cmd1)
	{
		free_chararr(pipex->cmd1);
		pipex->cmd1 = NULL;
	}
	if (pipex->cmd2)
	{
		free_chararr(pipex->cmd2);
		pipex->cmd2 = NULL;
	}
	if (pipex->path)
	{
		free_chararr(pipex->path);
		pipex->path = NULL;
	}
	if (pipex->absolute_path1)
	{
		free(pipex->absolute_path1);
		pipex->absolute_path1 = NULL;
	}
	if (pipex->absolute_path2)
	{
		free(pipex->absolute_path2);
		pipex->absolute_path2 = NULL;
	}
}


/*Split that will accept "Words like this as one because of the quotes" the logic is to keep track of the open single and pdouble quotes using the 2 booleans below*/

int	word_c_count(char *str, char c)
{
	int		i;
	int	count;
	bool	found_double;
	bool	found_single;

	found_double = false;
	found_single = false;
	i = 0;
	while (str[i] != '\0')
	{
		if(str[i] == '\"')
			found_double == !found_double;
		if(str[i] == '\'' && !found_double)
			found_single = !found_single;
		if(!found_double && !found_single && str[i] == c)
			count++;
		i++;
	}
}

char	**c_split(char *str, char c)
{
	char **arr;

	arr = malloc(sizeof(char *) * word_c_count(str, c))
}