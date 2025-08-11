/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:42:04 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/11 16:29:15 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void infile_cmd(t_pipex *pipex)
{
	fork();
}

//copilot snippet doe reference
// int fd[2];
// pipe(fd);

// pid_t pid = fork();
// if (pid == 0) {
//     // Child writes
//     close(fd[0]); // Close unused read end
//     write(fd[1], "hello", 5);
//     close(fd[1]);
// } else {
//     // Parent reads
//     close(fd[1]); // Close unused write end
//     char buf[10];
//     read(fd[0], buf, sizeof(buf));
//     printf("Parent read: %s\n", buf);
//     close(fd[0]);
// }


int clone_terminal(t_pipex *pipex)
{
	int fd[] = {0, 1};
}

int main(int argc, char **argv, char **env)
{
	t_pipex pipex;
	pipex.cmd1 = ft_split(argv[2], ' ');
	pipex.cmd2 = ft_split(argv[3], ' ');
	pipex.infile_fd = open(argv[1], O_RDONLY);
	if(pipex.infile_fd < 0)
		return(ft_printf("zsh: no such file or directory: %s\n", argv[1]), 127);
	pipex.outfile_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
	pipex.temp_file = open(".temp", O_WRONLY | O_CREAT | O_TRUNC);
	pipex.path = pathfinder(env);
	if(!(command_exist(pipex.cmd2[0], pipex.path)))
		return (127);
	
}


// int main(int argc, char **argv, char **env)
// {
// 	int *c1 = malloc(sizeof(int));
// 	int *c2 = malloc(sizeof(int));
// 	char **command1 = ft_split(argv[2], ' ');
// 	char **command2 = ft_split(argv[3], ' ');
// 	if(argc > 5)
// 		return (0);
// 	int infile;
// 	int outfile;
// 	infile = 1;
// 	if(infile < 0)
// 		return(ft_printf("zsh: no such file or directory: %s\n", argv[1]), 1);
// 	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
// 	char **path = pathfinder(env);
// 	if(!(command_exist(command1[0], path, c1) && command_exist(command2[0], path, c2)))
// 		return(ft_printf("No command G\n"));
// 	ft_printf("Command found");
// }
