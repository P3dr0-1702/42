/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackfirst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:23:55 by pfreire-          #+#    #+#             */
/*   Updated: 2025/05/15 16:25:48 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_stackfirst(t_stack *lst)
{
	t_stack	*i;

	if (!lst)
		return (NULL);
	i = lst;
	while (i->prev != NULL)
		i = i->prev;
	return (i);
}