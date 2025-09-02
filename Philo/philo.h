/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:31:18 by pfreire-          #+#    #+#             */
/*   Updated: 2025/09/02 11:30:11 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "limits.h"
# include "stdint.h"
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
	pthread_mutex_t		clairvoyant;
	unsigned int		meals;
}						t_philo;

typedef struct s_table
{
	t_philo				*philo;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print_lock;
	pthread_mutex_t		memento_lock;
	int					philo_nbr;
	int					eat_time;
	int					think_time;
	int					sleep_time;
	int					life_time;
	unsigned int		cycles;
	unsigned long int	start_time;
	int					memento_mori;
	pthread_t			grim_reaper;

}						t_table;

bool					is_only_nbr(char *str);
int						ft_atoi(const char *s);
void					msleep(t_philo *philo, unsigned long int a);
unsigned int			get_clock(t_table *table);
unsigned long			time_stamp(void);
void					*grim_reaper(void *arg);
void					drop_forks(t_philo *philo);
void					get_forks(t_philo *philo);
int						safe_print(t_philo *philo, const char *msg);
void					*existance(void *arg);
bool					only_nbrs(char *a);
bool					isvalid(char **argv);
void					*ft_calloc(size_t nmemb, size_t size);
int						cleanup(t_table *table, int forks, int clairs,
							int three);
int						clean_philos(t_table *table, int i);
void					philo_join(t_table *table);
#endif
