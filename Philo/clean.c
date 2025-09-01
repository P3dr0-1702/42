/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:28:02 by pfreire-          #+#    #+#             */
/*   Updated: 2025/09/01 18:28:55 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	cleanup(t_table *table, int forks, int clairs, int three)
{
	int	i;

	i = 0;
	if (!table)
		return (1);
	destroy_forks(table, forks);
	destroy_clairvoyants(table, clairs);
	if (three > 0)
		pthread_mutex_destroy(&table->print_lock);
	if (three > 1)
		pthread_mutex_destroy(&table->memento_lock);
	if (table->philo)
	{
		while (i < clairs)
		{
			if (table->philo[i].thread)
				free(table->philo[i].thread);
			i++;
		}
		free(table->philo);
	}
	if (table->forks)
		free(table->forks);
	return (free(table), 0);
}
