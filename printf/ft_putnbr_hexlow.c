/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexlow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:28:17 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/21 15:46:15 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hexlow(unsigned int nb, int *n)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nb >= 16)
		ft_putnbr_hexlow(nb / 16, n);
	ft_putchar(hex[nb % 16], n);
}
