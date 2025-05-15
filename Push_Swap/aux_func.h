/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_func.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:37:04 by pfreire-          #+#    #+#             */
/*   Updated: 2025/05/15 18:10:42 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUX_FUNC_H
#define AUX_FUNC_H

#include "lib/libft.h"

int	is_valid(char **array);
t_stack *mklst(char **array, t_stack **lst);

//operators
void	s_op(t_stack **lst);
void	p_op(t_stack **b, t_stack **a);
void r_op(t_stack **a);
void rr_op(t_stack **a);


#endif