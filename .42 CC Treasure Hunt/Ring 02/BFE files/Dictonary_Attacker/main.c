/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:52:48 by pedro             #+#    #+#             */
/*   Updated: 2025/09/15 12:52:41 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary_attacker.h"
#include <stdlib.h>
#include <unistd.h>

int	try_key(const char *binary, const char *file, const char *key)
{
	int		pipefd[2];
	pid_t	pid;
	int		status;
	int		devnull;

	if (pipe(pipefd) == 1)
		return (perror("Error Pipe:"), -1);
	pid = fork();
	if (pid < 0)
		return (perror("Error Fork: "), -1);
	if (pid == 0)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		char *const argv[] = {(char *)binary, (char *)file, NULL};
		devnull = open("/dev/null", O_WRONLY);
		if (devnull != -1)
		{
			dup2(devnull, STDERR_FILENO);
			close(devnull);
		}
		execve(binary, argv, NULL);
		perror("Error Execve: ");
		exit(127);
	}
	else
	{
		close(pipefd[0]);
		write(pipefd[1], key, ft_strlen(key));
		write(pipefd[1], "\n", 1);
		close(pipefd[1]);
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
		return (-1);
	}
}

int	parsing(char **argv)
{
	int	fd;

	fd = open(argv[2], O_RDONLY);
	if (fd < 0)
		return (ft_printf("Missing File or Permissions\n"), 1);
	close(fd);
	fd = open(argv[3], O_RDONLY);
	if (fd < 0)
		return (ft_printf("Missing File or Permissions\n"), 1);
	close(fd);
	fd = access(argv[1], X_OK | F_OK);
	if (fd < 0)
		return (ft_printf("Command Not Found or missing permissions\n"));
	return (0);
}

void	printf_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\n')
			write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*key;
	int		result;
	int		fd;

	if (argc != 4 || parsing(argv))
	{
		ft_printf("Wrong Arguments\n");
		ft_printf("Usage:\n");
		ft_printf("./Dictionary Attacker <Binary filer> <Encrypted File> <Dictionary File>\n");
		return (0);
	}
	fd = open(argv[3], O_RDONLY);
	while ((key = get_next_line(fd)) != NULL && ft_strcmp(key, "EOF\n") != 0)
	{
		result = try_key(argv[1], argv[2], key);
		if (result == 0)
			return (ft_printf("Decrypted With key %s\n", key), 0);
		ft_printf("Key: ");
		printf_nl(key);
		ft_printf(": failed :(\n");
		free(key);
	}
	return (0);
}
