/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_func.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:37:04 by pfreire-          #+#    #+#             */
/*   Updated: 2025/05/29 16:21:19 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUX_FUNC_H
# define AUX_FUNC_H

# include "lib/libft.h"
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>

int		is_valid(char **array);
t_stack	*mklst(char **array, t_stack **lst);
int		check_stack_status(t_stack *a, int is_reverse);
int		next_in_line(t_stack *solved, int current);
int		find_target(int curr, t_stack *solved);
int		rotation_judge(int index, int size);
void	rotate(t_stack **a, t_stack **b, t_stack *solved, int index,
			int is_reverse_rotation);
void	legal_solver(t_stack **a, t_stack **b, t_stack **solved);
int	check_stack_status(t_stack *a, int is_reverse);
t_stack	*ft_stack_newnode(int currNBR);
t_stack	*put_into_stack(t_stack *sorted, t_stack *node);
t_stack	*illegal_solver(t_stack **a);
void	rotate_sort(t_stack **a, t_stack **solved);
void	*indexer(t_stack **a2, t_stack **solved);


// operators
void	s_op(t_stack **lst, char is_a);
void	p_op(t_stack **b, t_stack **a, char is_a);
void	r_op(t_stack **a, char is_a);
void	rr_op(t_stack **a, char is_a);
void	ss_sop(t_stack **a, t_stack **b);
void	rr_sop(t_stack **a, t_stack **b, char print);
void	rrr_sop(t_stack **a, t_stack **b, char print);

#endif