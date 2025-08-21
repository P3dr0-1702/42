/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:48:28 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/21 12:53:12 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*foo(void *arg)
{
	char	*str;

	str = (char *)arg;
	printf("%s\n", str);
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t	thread1;
	char		*str;

	// if (argc < 5 || argc > 6)
	//	return (0);
	str = "Heloo woooooooooooooooooooooooorls";
	pthread_create(&thread1, NULL, foo, str);
	usleep(1);
	// pthread_join(thread1, NULL);
	printf("only the thread exited");
	return (1);
}
