/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 13:07:20 by pfreire-          #+#    #+#             */
/*   Updated: 2024/09/01 13:07:24 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0 || nb >= 13)
		return (0);
	else if (nb == 0)
		return (1);
	else
	{
		nb = nb * ft_recursive_factorial(nb - 1);
	}
	return (nb);
}
/*int main()
{
	unsigned int result;

	result = ft_recursive_factorial(3);
	printf("%d", result);
}*/
