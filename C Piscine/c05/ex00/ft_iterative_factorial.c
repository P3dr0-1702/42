/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 12:32:00 by pfreire-          #+#    #+#             */
/*   Updated: 2024/09/01 13:01:09 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	result;

	i = 1;
	result = nb;
	if (nb < 0 || nb >= 13)
	{
		return (0);
	}
	else if (nb == 0)
	{
		return (1);
	}
	else
	{
		while (i != result)
		{
			nb = nb * i;
			i++;
		}
		return (nb);
	}
}
/*int main()
{
	printf("%d", ft_iterative_factorial(3));
}*/
