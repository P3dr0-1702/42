/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:07:47 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/09 14:12:29 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *a, int c, size_t i);

void	ft_bzero(void *a, size_t i)
{
	ft_memset(a, 0, i);
}
