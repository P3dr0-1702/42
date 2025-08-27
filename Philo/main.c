/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:33:41 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/27 18:15:26 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	time_stamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

unsigned int	get_clock(t_table *table)
{
	return (time_stamp() - table->start_time);
}

int	safe_print(t_philo *philo, const char *msg)
{
	pthread_mutex_lock(&philo->table->print_lock);
	if (philo->table->memento_mori == 0)
	{
		printf("%u %d %s\n", get_clock(philo->table), philo->id,
			msg);
		pthread_mutex_unlock(&philo->table->print_lock);
		return (0);
	}
	usleep(1000);
	pthread_mutex_unlock(&philo->table->print_lock);
	return (0);
}

void	*grim_reaper(void *arg)
{
	t_table				*table;
	int					i;
	unsigned long int	now;

	table = (t_table *)arg;
	while (table->memento_mori == 0)
	{
		usleep(200);
		now = get_clock(table);
		i = 0;
		while (i < table->philo_nbr)
		{
			pthread_mutex_lock(&table->philo[i].clairvoyant);
			if (now >= table->philo[i].death_time)
			{
				pthread_mutex_lock(&table->print_lock);
				if(table->memento_mori == 0)
				{
					table->memento_mori = table->philo[i].id;
					printf("%lu %d has died\n", now, table->philo[i].id);
				}
				pthread_mutex_unlock(&table->print_lock);
				return NULL;
			}
			pthread_mutex_unlock(&table->philo[i].clairvoyant);
			i++;
		}
	}
	return (NULL);
}

void	cogito_ergo_sum(t_table *table, char **argv)
{
	int	i;

	table->memento_mori = 0;
	table->philo_nbr = atoi(argv[1]);
	table->life_time = atoi(argv[2]) * 1000;
	table->eat_time = atoi(argv[3]) * 1000;
	table->sleep_time = atoi(argv[4]) * 1000;
	table->cycles = -1;
	if (argv[5])
		table->cycles = atoi(argv[5]);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->philo_nbr);
	i = 0;
	while (i < table->philo_nbr)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&table->print_lock, NULL);
}

void	*existance(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->table->memento_mori == 0)
	{
		if (philo->id % 2 == 0 && philo->table->memento_mori == 0)
		{
			pthread_mutex_lock(&philo->table->forks[philo->left_fork]);
			pthread_mutex_lock(&philo->table->forks[philo->right_fork]);
		}
		else
		{
			pthread_mutex_lock(&philo->table->forks[philo->right_fork]);
			pthread_mutex_lock(&philo->table->forks[philo->left_fork]);
		}
		safe_print(philo, "is Eating");
		usleep(philo->table->eat_time);
		pthread_mutex_lock(&philo->clairvoyant);
		philo->death_time = get_clock(philo->table)
			+ philo->table->life_time / 1000;
		pthread_mutex_unlock(&philo->clairvoyant);
		pthread_mutex_unlock(&philo->table->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->table->forks[philo->right_fork]);
		safe_print(philo, "is Sleeping");
		usleep(philo->table->sleep_time);
		safe_print(philo, "is Thinking");
	}
	
	return (NULL);
}

void	start_philo(t_table *table)
{
	int	i;

	i = 0;
	table->philo = calloc(table->philo_nbr, sizeof(t_philo));
	while (i < table->philo_nbr)
	{
		table->philo[i].thread = malloc(sizeof(pthread_t));
		if (!table->philo[i].thread)
			return ;
		pthread_mutex_init(&table->philo[i].clairvoyant, NULL);
		table->philo[i].id = i + 1;
		table->philo[i].table = table;
		table->philo[i].left_fork = i;
		table->philo[i].right_fork = (i + 1) % table->philo_nbr;
		pthread_mutex_lock(&table->philo[i].clairvoyant);
		table->philo[i].death_time = get_clock(table) + table->life_time / 1000;
		pthread_mutex_unlock(&table->philo[i].clairvoyant);
		pthread_create(table->philo[i].thread, NULL, existance,
			(void *)&table->philo[i]);
		i++;
	}
	table->memento_mori = 0;
}

void cleanup(t_table *table)
{
	int i = 0;
	while (i< table->philo_nbr)
	{
		pthread_mutex_destroy(&table->forks[i]);
		pthread_mutex_destroy(&table->philo[i].clairvoyant);
		free(table->philo[i].thread);
		i++;
	}
	pthread_mutex_destroy(&table->print_lock);
	free(table->forks);
	free(table->philo);
	free(table);
}

int	main(int argc, char **argv)
{
	t_table	*table;
	int		i;

	table = malloc(sizeof(t_table));
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
	printf("Goona Cleanup\n");
	cleanup(table);
	return 0;
}
