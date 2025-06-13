/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:07:47 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/17 12:29:19 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Alocate memory with 0 in every index
/// @param a buffer to alocate
/// @param i size of buffer
void	ft_bzero(void *a, size_t i)
{
	ft_memset(a, 0, i);
}
