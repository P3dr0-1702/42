/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:23:07 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/18 11:10:44 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

void	ft_putchar(char c, int *n)
{
	write(1, &c, 1);
	(*n)++;
}