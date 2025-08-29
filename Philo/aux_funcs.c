/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 12:01:44 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/29 15:38:40 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *s)
{
	int			i;
	int			signal;
	long int	result;

	i = 0;
	result = 0;
	signal = 1;
	while ((s[i] && s[i] == ' ') || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-')
	{
		signal = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] != '\0' && (s[i] >= '0' && s[i] <= '9'))
	{
		result *= 10;
		result += (s[i] - '0');
		if (result > INT_MAX)
			return (-1);
		i++;
	}
	return ((int)result * signal);
}

bool	is_only_nbr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 48 || str[i] > 57)
			return (false);
		i++;
	}
	return (true);
}

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

void	msleep(t_philo *philo, unsigned long int a)
{
	unsigned long int	i;
	int					morti;
	unsigned long int	end;

	i = get_clock(philo->table);
	end = i + (a / 1000);
	while (i < end)
	{
		pthread_mutex_lock(&philo->table->memento_lock);
		morti = philo->table->memento_mori;
		pthread_mutex_unlock(&philo->table->memento_lock);
		if (morti != 0)
			break ;
		usleep(10);
		i = get_clock(philo->table);
	}
}

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
