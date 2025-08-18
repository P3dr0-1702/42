/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:48:49 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/18 11:00:36 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <errno.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

char		**pathfinder(char **env);
int			command_exist(char *command, char **path);

typedef struct s_pipex
{
	char	**cmd1;
	char	**cmd2;
	char	**path;
	int		infile_fd;
	int		outfile_fd;
	char	*absolute_path1;
	char	*absolute_path2;
	char	*infile;
	char	*outfile;
	int		fd[2];
	char	**env;
}			t_pipex;

#endif