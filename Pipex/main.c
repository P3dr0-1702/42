/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:45:53 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/14 18:13:36 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_arr(char **c)
{
	int	i;

	i = 0;
	while (c[i] != NULL)
	{
		if (c[i])
			free(c[i]);
		i++;
	}
	free(c);
}

void	free_pipex(t_pipex *pipex)
{
	if (pipex->cmd1)
		free_arr(pipex->cmd1);
	if (pipex->cmd2)
		free_arr(pipex->cmd2);
	if (pipex->path)
		free_arr(pipex->path);
	// if(pipex->env)
	// 	free_arr(pipex->env);
	if (pipex->absolute_path1)
		free(pipex->absolute_path1);
	if (pipex->absolute_path2)
		free(pipex->absolute_path2);
}

void	pipexx(t_pipex *pipex)
{
	pid_t	pid;
	pid_t	pid2;

	pid = fork();
	if (pid == 0)
	{
		dup2(pipex->infile_fd, STDIN_FILENO);
		dup2(pipex->fd[1], STDOUT_FILENO);
		close(pipex->fd[0]);
		close(pipex->fd[1]);
		close(pipex->infile_fd);
		close(pipex->outfile_fd);
		execve(pipex->absolute_path1, &pipex->cmd1[0], pipex->env);
		perror("execve");
		free_pipex(pipex);
		exit(1);
	}
	close(pipex->infile_fd);
	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(pipex->fd[0], STDIN_FILENO);
		dup2(pipex->outfile_fd, STDOUT_FILENO);
		close(pipex->fd[1]);
		close(pipex->fd[0]);
		close(pipex->outfile_fd);
		execve(pipex->absolute_path2, &pipex->cmd2[0], pipex->env);
		perror("execve");
		free_pipex(pipex);
		exit(127);
	}
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	close(pipex->outfile_fd);
	waitpid(pid, NULL, 0);
	waitpid(pid2, NULL, 0);
	free_pipex(pipex);
}

char	*command_to_str(char **path, char *command)
{
	int		i;
	int		fd;
	char	*path_slash;
	char	*absolute_path;

	i = 0;
	fd = 0;
	while (path[i] != NULL)
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
	fd = access(command, F_OK);
	if(fd == 0)
		return(command);
	return(NULL);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	// char	*str;
	// char	*str2;
	// int		str_1;
	// int		str_2;

	if (argc != 5)
		return (ft_printf("Not those args\n"), -1);
	ft_bzero(&pipex, sizeof(t_pipex));
	pipex.cmd1 = ft_split(argv[2], ' ');
	pipex.cmd2 = ft_split(argv[3], ' ');
	pipex.infile_fd = open(argv[1], O_RDONLY);
	if (pipex.infile_fd < 0)
		return (ft_printf("bash: no such file or directory: %s\n", argv[1]), 1);
	pipex.path = pathfinder(env);
	// str_1 = command_exist(pipex.cmd1[0], pipex.path);
	// str = NULL;
	// if (str_1 >= 0)
	// 	str = ft_strjoin(pipex.path[str_1], "/");
	// str_2 = command_exist(pipex.cmd2[0], pipex.path);
	// if (str_2 >= 0)
	// 	str2 = ft_strjoin(pipex.path[str_2], "/");
	// if (str_2 == -1)
	// {
	// 	free(str);
	// 	free_pipex(&pipex);
	// 	exit(127);
	// }
	// ft_printf("%s\n", str);
	// ft_printf("%s\n", str2);
	pipex.absolute_path1 = command_to_str(pipex.path, pipex.cmd1[0]);
	pipex.absolute_path2 = command_to_str(pipex.path, pipex.cmd2[0]);
	pipex.outfile_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	// free(str);
	// free(str2);
	pipex.env = env;
	pipe(pipex.fd);
	// if (command_exist(pipex.cmd1[0], pipex.path))
	// 	ft_printf("%d\n", pipex.fd[1]);
	pipexx(&pipex);
	return (0);
}
