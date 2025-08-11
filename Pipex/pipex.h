/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:48:49 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/11 16:02:12 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"

char		**pathfinder(char **env);
bool		command_exist(char *command, char **path);

typedef struct s_pipex
{
	char	**cmd1;
	char	**cmd2;
	char	**path;
	int		infile_fd;
	int		outfile_fd;
	int		temp_file;
}			t_pipex;

#endif