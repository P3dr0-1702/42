/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:42:24 by pfreire-          #+#    #+#             */
/*   Updated: 2024/08/31 14:52:06 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	int	result;

	result = nb;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (nb == 1)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}
/*int main()
{
	int	nb;
	int	power;

	nb = 2;
	power = 4;
	printf("%d\n", ft_recursive_power(nb, power));
}*/
