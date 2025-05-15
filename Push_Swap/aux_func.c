/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:23:12 by pfreire-          #+#    #+#             */
/*   Updated: 2025/05/15 18:10:52 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_func.h"

int	is_valid(char **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i] != NULL)
	{
		j = 0;
		while (array[i][j] != '\0')
		{
			if (!(ft_isdigit(array[i][j])))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_stack	*mklst(char **array, t_stack **lst)
{
	int i;
	int k;
	t_stack *lstb;

	i = 0;
	k = 0;
	*lst = NULL;
	lstb = NULL;
	while (array[i] != NULL)
	{
		ft_stackadd_back(lst, ft_stacknew(ft_atoi(array[i])));
		i++;
	}
	while (k < ft_lstsize(lst))
	{
		ft_stackadd_back(lstb, ft_stacknew(NULL));
		k++;
	}
	return (lstb);
}