/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:31:18 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/22 12:18:42 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_table	t_table;

typedef struct s_philo
{
	int					id;
	pthread_t			*thread;
	t_table				*table;
	int					left_fork;
	int					right_fork;
	unsigned long int	death_time;
}						t_philo;

typedef struct s_table
{
	t_philo				*philo;
	pthread_mutex_t		*forks;
	int					philo_nbr;
	int					eat_time;
	int					think_time;
	int					sleep_time;
	int					life_time;
	int					cycles;
	unsigned long int	clock;
	int					memento_mori;
	pthread_t			grim_reaper;

}						t_table;

bool					is_only_nbr(char *str);
int						ft_atoi(const char *s);
#endif
