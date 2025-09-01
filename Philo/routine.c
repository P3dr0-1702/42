/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:10:44 by pfreire-          #+#    #+#             */
/*   Updated: 2025/09/01 18:25:43 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>

void	*one_must_imagine_socrates_happy(t_philo *philo)
{
	safe_print(philo, "has taken a fork");
	msleep(philo, philo->table->life_time / 1000);
	return (NULL);
}

bool	inescapable_dread(t_philo *philo)
{
	pthread_mutex_unlock(&philo->table->memento_lock);
	get_forks(philo);
	pthread_mutex_lock(&philo->clairvoyant);
	philo->meals++;
	philo->death_time = get_clock(philo->table) + philo->table->life_time
		/ 1000;
	if (philo->meals >= philo->table->cycles)
		return (pthread_mutex_unlock(&philo->clairvoyant), drop_forks(philo),
			false);
	pthread_mutex_unlock(&philo->clairvoyant);
	msleep(philo, philo->table->eat_time);
	drop_forks(philo);
	safe_print(philo, "is sleeping");
	msleep(philo, philo->table->sleep_time);
	safe_print(philo, "is thinking");
	if (philo->table->philo_nbr % 2 != 0)
		msleep(philo, (2 * philo->table->eat_time) - philo->table->sleep_time);
	pthread_mutex_lock(&philo->table->memento_lock);
	return (true);
}

void	*existance(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(philo->table->eat_time / 2);
	if (philo->table->philo_nbr == 1)
		return (one_must_imagine_socrates_happy(philo));
	pthread_mutex_lock(&philo->table->memento_lock);
	while (philo->table->memento_mori == 0)
	{
		if (!inescapable_dread(philo))
			return (NULL);
	}
	pthread_mutex_unlock(&philo->table->memento_lock);
	return (NULL);
}
