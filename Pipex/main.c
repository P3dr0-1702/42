/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:26:14 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/19 17:42:00 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	first_command(t_pipex *pipex)
{
	pipex->infile_fd = open(pipex->infile, O_RDONLY);
	if (pipex->infile_fd < 0)
	{
		perror(pipex->infile);
		exit(1);
	}
	dup2(pipex->infile_fd, STDIN_FILENO);
	dup2(pipex->fd[1], STDOUT_FILENO);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	close(pipex->infile_fd);
	execve(pipex->absolute_path1, pipex->cmd1, pipex->env);
	if (errno == ENOENT)
	{
		ft_dprintf(2, "%s: command not found\n", pipex->cmd1[0]);
		return (free_pipex(pipex), exit(127), 1);
	}
	else if (errno == EACCES)
	{
		ft_dprintf(2, "%s: Permission denied\n", pipex->cmd1[0]);
		return (free_pipex(pipex), exit(126), 1);
	}
	else
		return (free_pipex(pipex), exit(1), 1);
}

int	second_command(t_pipex *pipex)
{
	dup2(pipex->fd[0], STDIN_FILENO);
	pipex->outfile_fd = open(pipex->outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile_fd < 0)
	{
		perror(pipex->outfile);
		exit(1);
	}
	dup2(pipex->outfile_fd, STDOUT_FILENO);
	close(pipex->fd[1]);
	close(pipex->fd[0]);
	close(pipex->outfile_fd);
	execve(pipex->absolute_path2, pipex->cmd2, pipex->env);
	if (errno == ENOENT)
	{
		ft_dprintf(2, "%s: command not found\n", pipex->cmd2[0]);
		return (free_pipex(pipex), exit(127), 1);
	}
	else if (errno == EACCES)
	{
		ft_dprintf(2, "%s: Permission denied\n", pipex->cmd2[0]);
		return (free_pipex(pipex), exit(126), 1);
	}
	else
		return (free_pipex(pipex), exit(1), 1);
}

char	*command_to_str(char **path, char *command)
{
	int		i;
	int		fd;
	char	*path_slash;
	char	*absolute_path;

	i = 0;
	fd = 0;
	if (!command)
		return (NULL);
	while (path && path[i] != NULL)
	{
		path_slash = ft_strjoin(path[i], "/");
		absolute_path = ft_strjoin(path_slash, command);
		fd = access(absolute_path, F_OK);
		if (fd == 0)
		{
			free(path_slash);
			return (absolute_path);
		}
		i++;
		free(path_slash);
		free(absolute_path);
	}
	return (ft_strdup(command));
}

t_pipex	init_pipex(char **argv, char **env)
{
	t_pipex	pipex;

	ft_bzero(&pipex, sizeof(t_pipex));
	pipex.cmd1 = ft_split(argv[2], ' ');
	pipex.cmd2 = ft_split(argv[3], ' ');
	if (!pipex.cmd1 || !pipex.cmd2)
	{
		ft_printf("Download more RAM\n");
		free_pipex(&pipex);
		exit(1);
	}
	pipex.path = pathfinder(env);
	pipex.absolute_path1 = command_to_str(pipex.path, pipex.cmd1[0]);
	pipex.absolute_path2 = command_to_str(pipex.path, pipex.cmd2[0]);
	pipe(pipex.fd);
	pipex.infile = argv[1];
	pipex.outfile = argv[4];
	pipex.env = env;
	return (pipex);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	pid_t	child1;
	pid_t	child2;
	int		status;

	if (argc != 5)
		return (ft_printf("Not those args\n"), -1);
	pipex = init_pipex(argv, env);
	child1 = fork();
	if (child1 == 0)
		first_command(&pipex);
	close(pipex.fd[1]);
	waitpid(child1, NULL, 0);
	child2 = fork();
	if (child2 == 0)
		second_command(&pipex);
	close(pipex.fd[0]);
	waitpid(child2, &status, 0);
	free_pipex(&pipex);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}
