/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_func.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:45:31 by pfreire-          #+#    #+#             */
/*   Updated: 2025/06/16 17:03:57 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUX_FUNC_H
# define AUX_FUNC_H

# include "lib/libft.h"

// push_swap ops
void	s_op(t_stack **lst, char is_a);
void	p_op(t_stack **from, t_stack **to, char is_a);
void	r_op(t_stack **a, char is_a);
void	rr_op(t_stack **a, char is_a);
void	ss_sop(t_stack **a, t_stack **b);
void	rr_sop(t_stack **a, t_stack **b, char *print);
void	rrr_sop(t_stack **a, t_stack **b, char *print);

// illegal solve funcs
t_stack	*illegal_solver(t_stack **a);
t_stack	*put_into_stack(t_stack *sorted, t_stack *node);
t_stack	*ft_stack_newnode(int currNBR);
int		check_stack_status(t_stack *a, int is_reverse);

// testing funcs
void	print_stack(t_stack **a);
void	indexer(t_stack **a2, t_stack **solved);
void	indexer2(t_stack **solved2);
int		arr_size(int *arr);
void	print_list(t_list **a);

// organizer funcs
void	organizer(t_stack **g, t_stack **solved);
void	stack_eater(t_stack *a);
t_list	*LIS_tractor(t_stack *stack);

//solver funcs
void	bouncer(t_stack **a, t_stack **b, t_list *LIS);
int		is_in_the_LIS_list(t_list *LIS, int *val);
void	rotation_judge(t_stack **b, int index);
int		find_index(t_stack *b, int value);

// void	comparator(t_stack **a, t_stack **b, t_stack **solving);
// void	rotator(t_stack **a, t_stack **b, t_stack **solving);
#endif
