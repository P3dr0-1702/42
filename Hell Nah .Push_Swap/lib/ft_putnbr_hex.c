/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:54:39 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/21 15:36:12 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_hex(unsigned int nb)
{
	char	*hex;

	hex = "0123456789ABCDEF";
	if (nb >= 16)
		ft_putnbr_hex(nb / 16);
	ft_putchar(hex[nb % 16]);
}
