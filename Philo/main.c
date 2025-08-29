/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:33:41 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/29 16:03:16 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

void destroy_forks(t_table *table, int done)
{
	int i = 0;
	while(i < done)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
}

void destroy_clairvoyants(t_table *table, int done)
{
	int i = 0;
	while(i < done)
	{
		pthread_mutex_destroy(&table->philo[i].clairvoyant);
		i++;
	}
}

void	cleanup(t_table *table, int code)
{
	int	i;

	i = 0;
	if (!table)
		return ;
	while (code == 999 && i < table->philo_nbr)
	{
		pthread_mutex_destroy(&table->forks[i]);
		pthread_mutex_destroy(&table->philo[i].clairvoyant);
		free(table->philo[i].thread);
		i++;
	}
	pthread_mutex_destroy(&table->print_lock);
	pthread_mutex_destroy(&table->memento_lock);
	free(table->forks);
	free(table->philo);
	free(table);
}

int	safe_print(t_philo *philo, const char *msg)
{
	if (philo->table->memento_mori != 0)
		return (0);
	pthread_mutex_lock(&philo->table->memento_lock);
	pthread_mutex_lock(&philo->table->print_lock);
	if (philo->table->memento_mori == 0)
		printf("%u %d %s\n", get_clock(philo->table), philo->id, msg);
	pthread_mutex_unlock(&philo->table->print_lock);
	pthread_mutex_unlock(&philo->table->memento_lock);
	return (0);
}

void	cogito_ergo_sum(t_table *table, char **argv)
{
	int	i;

	table->memento_mori = 0;
	table->philo_nbr = ft_atoi(argv[1]);
	table->life_time = ft_atoi(argv[2]) * 1000;
	table->eat_time = ft_atoi(argv[3]) * 1000;
	table->sleep_time = ft_atoi(argv[4]) * 1000;
	table->cycles = -1;
	if (argv[5])
		table->cycles = atoi(argv[5]);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->philo_nbr);
	//table->forks = NULL;
	if (!table->forks)
	{
		cleanup(table, 0);
		return ;
	}
	i = 0;
	while (i < table->philo_nbr)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&table->print_lock, NULL);
	pthread_mutex_init(&table->memento_lock, NULL);
}

void	get_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->table->forks[philo->left_fork]);
		safe_print(philo, "has taken a fork");
		pthread_mutex_lock(&philo->table->forks[philo->right_fork]);
		safe_print(philo, "has taken a fork");
		safe_print(philo, "is eating");
	}
	else
	{
		pthread_mutex_lock(&philo->table->forks[philo->right_fork]);
		safe_print(philo, "has taken a fork");
		pthread_mutex_lock(&philo->table->forks[philo->left_fork]);
		safe_print(philo, "has taken a fork");
		safe_print(philo, "is eating");
	}
}

void	drop_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&philo->table->forks[philo->right_fork]);
		// safe_print(philo, "has dropped a right fork");
		pthread_mutex_unlock(&philo->table->forks[philo->left_fork]);
		// safe_print(philo, "has dropped a left fork");
	}
	else
	{
		pthread_mutex_unlock(&philo->table->forks[philo->left_fork]);
		// safe_print(philo, "has dropped a left fork");
		pthread_mutex_unlock(&philo->table->forks[philo->right_fork]);
		// safe_print(philo, "has dropped a right fork");
	}
}

void	start_philo(t_table *table)
{
	int	i;

	i = 0;
	table->philo = ft_calloc(table->philo_nbr, sizeof(t_philo));
	while (i < table->philo_nbr)
	{
		table->philo[i].thread = malloc(sizeof(pthread_t));
		if (!table->philo[i].thread)
			return ;
		pthread_mutex_init(&table->philo[i].clairvoyant, NULL);
		table->philo[i].id = i + 1;
		table->philo[i].table = table;
		table->philo[i].left_fork = i;
		table->philo[i].meals = 0;
		table->philo[i].right_fork = (i + 1) % table->philo_nbr;
		pthread_mutex_lock(&table->philo[i].clairvoyant);
		table->philo[i].death_time = get_clock(table) + table->life_time / 1000;
		pthread_mutex_unlock(&table->philo[i].clairvoyant);
		pthread_create(table->philo[i].thread, NULL, existance,
			(void *)&table->philo[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_table	*table;
	int		i;

	if ((argc < 5 || argc > 6) || !isvalid(argv))
		return (printf("Wrong args\n"), 0);
	table = malloc(sizeof(t_table));
	if(!table)
		cleanup(table, 0);
	table->start_time = time_stamp();
	cogito_ergo_sum(table, argv);
	start_philo(table);
	i = 0;
	pthread_create(&table->grim_reaper, NULL, grim_reaper, (void *)table);
	pthread_join(table->grim_reaper, NULL);
	while (i < table->philo_nbr)
	{
		pthread_join(*table->philo[i].thread, NULL);
		i++;
	}
	cleanup(table, 999);
	return (0);
}
