/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_aux_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:26:15 by pfreire-          #+#    #+#             */
/*   Updated: 2025/09/02 13:03:34 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_memset(void *a, int c, size_t i)
{
	size_t			j;
	unsigned char	*str;

	if (!a)
		return (NULL);
	str = (unsigned char *)a;
	j = 0;
	while (j < i)
	{
		str[j] = (unsigned char)c;
		j++;
	}
	return (a);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buffer;

	if ((nmemb == 0 || size == 0))
		return (malloc(0));
	if (nmemb > (SIZE_MAX) / size)
		return (NULL);
	buffer = malloc(nmemb * size);
	if (buffer == NULL)
		return (NULL);
	ft_memset(buffer, 0, nmemb * size);
	return (buffer);
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
		pthread_mutex_unlock(&philo->table->forks[philo->left_fork]);
	}
	else
	{
		pthread_mutex_unlock(&philo->table->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->table->forks[philo->right_fork]);
	}
}

void	philo_join(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nbr)
	{
		pthread_join(*table->philo[i].thread, NULL);
		i++;
	}
}
