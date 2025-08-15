/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:26:14 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/15 12:58:34 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void cmd_permissions(char *abs_path)
{
	int fd;
	fd = 
}

int	infile_permissions(char *file)
{
	int	fd;

	fd = acess(file, F_OK);
	if (fd < 0)
	{
		ft_printf("bash: %s: No such file\n", file);
		exit(1);
	}
	fd = acess(file, R_OK);
	if(fd < 0)
	{
		ft_printf("bash: %s: Permission denied\n", file);
		exit(1);
	}
	fd = open();
}

void	first_command(t_pipex *pipex)
{
	dup2(pipex->fd[1], STDOUT_FILENO);
	pipex->infile_fd = access(pipex->infile, F_OK);
	infile_permissions(pipex->infile);
	dup2(pipex->infile_fd, STDIN_FILENO);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	close(pipex->infile_fd);
	close(pipex->outfile_fd);
	execve(pipex->absolute_path1, &pipex->cmd1[0], pipex->env);
	perror("execve");
	free_pipex(pipex);
	exit(1);
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
	if (fd == 0)
		return (command);
	return (NULL);
}

t_pipex	init_pipex(char **argv, char **env)
{
	t_pipex	pipex;

	ft_bzero(&pipex, sizeof(t_pipex));
	pipex.cmd1 = ft_split(argv[2], ' ');
	pipex.cmd2 = ft_split(argv[3], ' ');
	pipex.path = pathfinder(env);
	pipex.absolute_path1 = command_to_str(pipex.path, pipex.cmd1[0]);
	pipex.absolute_path2 = command_to_str(pipex.path, pipex.cmd2[0]);
	pipe(pipex.fd);
	pipex.infile = argv[1];
	pipex.outfile = argv[4];
}

int	main(int argc, char **argv, char **env)
{
	t_pipex pipex;
	pid_t child1;
	pid_t child2;

	if (argc != 5)
		return (ft_printf("Not those args\n"), -1);
	pipex = init_pipex(argv, env);
	child1 = fork();
	if (child1 == 0)
		first_command(pipex);
}