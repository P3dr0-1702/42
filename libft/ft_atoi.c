/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 12:02:53 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/10 10:51:08 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	what_signal(const char *str, int *i)
{
	int	sign;

	sign = 1;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
	{
		(*i)++;
	}
	while (str[*i] != '\0' && (str[*i] == 45 || str[*i] == 43))
	{
		if (str[*i] == 45)
		{
			sign *= -1;
		}
		(*i)++;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	signal1;
	int	result;

	i = 0;
	result = 0;
	signal1 = what_signal(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * signal1);
}
