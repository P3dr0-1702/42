/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:18:49 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/18 14:53:54 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

void	ft_putnbr(int nb, int *n)
{
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648", n);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-', n);
		nb = nb * -1;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10, n);
	ft_putchar((nb % 10) + '0', n);
}
