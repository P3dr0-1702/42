/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:28:02 by pfreire-          #+#    #+#             */
/*   Updated: 2025/09/02 13:03:42 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void	destroy_forks(t_table *table, int done)
{
	int	i;

	i = 0;
	while (i < done)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
}

void	destroy_clairvoyants(t_table *table, int done)
{
	int	i;

	i = 0;
	while (i < done)
	{
		pthread_mutex_destroy(&table->philo[i].clairvoyant);
		i++;
	}
}

void	handle_clairs(t_table *table, int clairs)
{
	int	i;

	i = 0;
	if (clairs == 0)
		free(table->philo[0].thread);
	if (clairs > -2 && table->philo)
	{
		while (i < clairs)
		{
			if (table->philo[i].thread)
				free(table->philo[i].thread);
			i++;
		}
		free(table->philo);
	}
}

int	cleanup(t_table *table, int forks, int clairs, int three)
{
	if (!table)
		return (1);
	destroy_forks(table, forks);
	destroy_clairvoyants(table, clairs);
	if (three > 0)
		pthread_mutex_destroy(&table->print_lock);
	if (three > 1)
		pthread_mutex_destroy(&table->memento_lock);
	handle_clairs(table, clairs);
	if (clairs > -3 && table->forks)
		free(table->forks);
	return (free(table), 0);
}

int	clean_philos(t_table *table, int i)
{
	int	j;

	j = 0;
	pthread_mutex_lock(&table->memento_lock);
	table->memento_mori = 1;
	pthread_mutex_unlock(&table->memento_lock);
	while (j < i)
	{
		pthread_join(*table->philo[j].thread, NULL);
		j++;
	}
	return (cleanup(table, table->philo_nbr, i, 2), 1);
}
