/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 12:02:53 by pfreire-          #+#    #+#             */
/*   Updated: 2024/09/01 12:04:59 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	what_signal(char *str, int *i)
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

int	ft_atoi(char *str)
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
/*int main()
{
	int i = ft_atoi("-------------------+123456 7asd8");
	printf("%d", i);
}*/
