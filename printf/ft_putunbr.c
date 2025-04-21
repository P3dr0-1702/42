/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:18:49 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/21 15:46:23 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr(unsigned int nb, int *n)
{
	if (nb >= 10)
	{
		ft_putunbr(nb / 10, n);
		ft_putunbr(nb % 10, n);
	}
	if (nb < 10)
	{
		ft_putchar(nb + '0', n);
	}
}
