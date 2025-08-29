/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grim_reaper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:04:52 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/29 16:03:53 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	scythe(t_table *table, unsigned long int now, int *i, int *j)
{
	pthread_mutex_lock(&table->memento_lock);
	pthread_mutex_lock(&table->philo[*i].clairvoyant);
	if (now > table->philo[*i].death_time)
	{
		table->memento_mori = table->philo[*i].id;
		pthread_mutex_lock(&table->print_lock);
		printf("%lu %d died\n", now, table->philo[*i].id);
		return (pthread_mutex_unlock(&table->print_lock),
			pthread_mutex_unlock(&table->philo[*i].clairvoyant),
			pthread_mutex_unlock(&table->memento_lock), false);
	}
	if (table->cycles <= table->philo[*i].meals)
		(*j)++;
	pthread_mutex_unlock(&table->philo[*i].clairvoyant);
	pthread_mutex_unlock(&table->memento_lock);
	(*i)++;
	return(true);
}

void	*grim_reaper(void *arg)
{
	t_table *table;
	int i;
	unsigned long int now;
	int j;

	table = (t_table *)arg;
	while (table->memento_mori == 0)
	{
		usleep(200);
		now = get_clock(table);
		i = 0;
		j = 0;
		while (i < table->philo_nbr)
		{
			if(!(scythe(table, now, &i, &j)))
				return(NULL);
		}
		if (j >= table->philo_nbr)
			return (NULL);
	}
	return (NULL);
}