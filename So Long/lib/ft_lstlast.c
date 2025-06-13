/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:29:55 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/17 12:39:09 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Returns lat node of a list
/// @param lst list
/// @return node
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*i;

	if (!lst)
		return (NULL);
	i = lst;
	while (i->next != NULL)
		i = i->next;
	return (i);
}
