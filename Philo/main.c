/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:48:28 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/22 12:18:44 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void cogito_ergo_sum(t_table *table, char **argv)
{
	table->philo_nbr = atoi(argv[1]);
	table->life_time = atoi(argv[2]);
	table->eat_time = atoi(argv[3]);
	table->sleep_time = atoi(argv[4]);
	if(argv[5])
		table->cycles = atoi(argv[5]);
}


bool is_valid(char **argv)
{
	int i = 0;
	while(argv[i] != NULL)
	{
		if(!is_only_nbr(argv[i]))
			return false;
		i++;
	}

	return(true);
}

int	main(int argc, char **argv)
{
	pthread_t	thread1;
	char		*str;
	t_table	table;
	if(!is_valid(argv))
		return(0);
	cogito_ergo_sum(&table, argv);
	// if (argc < 5 || argc > 6)
	//	return (0);
	str = "Heloo woooooooooooooooooooooooorls";
	//pthread_create(&thread1, NULL, foo, str);
	usleep(1);
	// pthread_join(thread1, NULL);
	printf("only the thread exited");
	return (1);
}
