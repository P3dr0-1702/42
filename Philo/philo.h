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
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include "stdbool.h"

typedef struct s_philo
{
	int					id;
}						t_philo;

typedef struct s_table
{
	t_philo				*philos;
	int					philo_nbr;
	int	eat_time;
	int sleep_time;
	int life_time;
	int cycles;
	unsigned long int	time;
}						t_table;

bool is_only_nbr(char *str);
int						ft_atoi(const char *s);
#endif
