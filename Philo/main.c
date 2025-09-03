/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:33:41 by pfreire-          #+#    #+#             */
/*   Updated: 2025/09/02 14:27:21 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>
#include <pthread.h>
#include <unistd.h>

int	safe_print(t_philo *philo, const char *msg)
{
	pthread_mutex_lock(&philo->table->memento_lock);
	pthread_mutex_lock(&philo->table->print_lock);
	if (philo->table->memento_mori == 0)
		printf("%u %d %s\n", get_clock(philo->table), philo->id, msg);
	pthread_mutex_unlock(&philo->table->print_lock);
	pthread_mutex_unlock(&philo->table->memento_lock);
	return (0);
}

int	cogito_ergo_sum(t_table *table, char **argv)
{
	int	i;

	table->memento_mori = 0;
	table->philo_nbr = ft_atoi(argv[1]);
	table->life_time = ft_atoi(argv[2]) * 1000;
	table->eat_time = ft_atoi(argv[3]) * 1000;
	table->sleep_time = ft_atoi(argv[4]) * 1000;
	table->cycles = -1;
	if (argv[5])
		table->cycles = ft_atoi(argv[5]);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->philo_nbr);
	if (!table->forks)
		return (cleanup(table, 0, -2, 0), 1);
	i = 0;
	while (i < table->philo_nbr)
	{
		if (pthread_mutex_init(&table->forks[i], NULL))
			return (cleanup(table, i, -2, 0), 1);
		i++;
	}
	if (pthread_mutex_init(&table->print_lock, NULL))
		return (cleanup(table, i, -2, 1), 1);
	if (pthread_mutex_init(&table->memento_lock, NULL))
		return (cleanup(table, i, -2, 2), 1);
	return (0);
}

void	init_philo(t_table *table, int i)
{
	table->philo[i].id = i + 1;
	table->philo[i].table = table;
	table->philo[i].left_fork = i;
	table->philo[i].meals = 0;
	table->philo[i].right_fork = (i + 1) % table->philo_nbr;
}

int	start_philo(t_table *table)
{
	int	i;

	i = 0;
	table->philo = ft_calloc(table->philo_nbr, sizeof(t_philo));
	if (!table->philo)
		return (cleanup(table, table->philo_nbr, -1, 2), 1);
	while (i < table->philo_nbr)
	{
		table->philo[i].thread = malloc(sizeof(pthread_t));
		if (!table->philo[i].thread)
			return (clean_philos(table, i));
		if (pthread_mutex_init(&table->philo[i].clairvoyant, NULL))
			return (clean_philos(table, i));
		init_philo(table, i);
		pthread_mutex_lock(&table->philo[i].clairvoyant);
		table->philo[i].death_time = get_clock(table) + table->life_time / 1000;
		pthread_mutex_unlock(&table->philo[i].clairvoyant);
		if (pthread_create(table->philo[i].thread, NULL, existance,
				(void *)&table->philo[i]))
			return (clean_philos(table, i + 1));
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_table	*table;
	int		i;

	if ((argc < 5 || argc > 6) || !isvalid(argv))
		return (printf("Wrong args\n"), 0);
	table = malloc(sizeof(t_table));
	if (!table)
		return (cleanup(table, 0, -3, 0), 1);
	table->start_time = time_stamp();
	if (cogito_ergo_sum(table, argv))
		return (printf("Download more RAM or something\n"), 1);
	if (start_philo(table))
	{
		return (printf("Download more RAM\n"), 1);
	}
	i = 0;
	if (pthread_create(&table->grim_reaper, NULL, grim_reaper, (void *)table))
		return (cleanup(table, table->philo_nbr, table->philo_nbr, 2), 1);
	philo_join(table);
	pthread_join(table->grim_reaper, NULL);
	return (cleanup(table, table->philo_nbr, table->philo_nbr, 2), 0);
}
