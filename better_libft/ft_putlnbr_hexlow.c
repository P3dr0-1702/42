/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr_hexlow.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:28:17 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/21 15:38:45 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlnbr_hexlow(unsigned int nb, int *n)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nb >= 16)
		ft_putlnbr_hexlow(nb / 16, n);
	ft_putlchar(hex[nb % 16], n);
}
