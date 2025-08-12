/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:48:49 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/12 14:58:10 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

char		**pathfinder(char **env);
int		command_exist(char *command, char **path);

typedef struct s_pipex
{
	char	**cmd1;
	char	**cmd2;
	char	**path;
	int		infile_fd;
	int		outfile_fd;
	int		temp_file;
	char	*absolute_path1;
	char	*absolute_path2;
	int	path_index1;
	int	path_index2;
	int	fd[2];
	char	**env;
}			t_pipex;

#endif