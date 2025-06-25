/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_func.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:45:31 by pfreire-          #+#    #+#             */
/*   Updated: 2025/06/24 15:27:47 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUX_FUNC_H
# define AUX_FUNC_H

# include "lib/libft.h"

// Auxiliary Functions
void	print_stack(t_stack **a);
void	indexer(t_stack **a2, t_stack **solved);
void	indexer2(t_stack **solved2);
void	print_list(t_list **a);

// Non-PS Solver
t_stack	*non_ps_solver(t_stack **a);
t_stack	*put_into_stack(t_stack *sorted, t_stack *node);
t_stack	*ft_stack_newnode(int currNBR);

// Lazy Mover
int		get_node_index(t_stack *a, t_stack *target);
void	move_cheapest_a2b(t_stack **a, t_stack **b, t_list *LIS);
int		notmembers_of_lis(t_stack *a, t_list *LIS);

// Lazy Unmover
void	rotation_judge_b2a(t_stack **a, t_stack **b, int indexa, int indexb);
void	move_cheapest_b2a(t_stack **a, t_stack **b, t_list *LIS);

// LIS list
t_list	*lis_tractor(t_stack *stack);

// Push Swap Operations
void	s_op(t_stack **lst, char is_a);
void	p_op(t_stack **from, t_stack **to, char is_a);
void	r_op(t_stack **a, char is_a);
void	rr_op(t_stack **a, char is_a);

// Push Swap Simultaneous Operations
void	ss_sop(t_stack **a, t_stack **b);
void	rr_sop(t_stack **a, t_stack **b, char *print);
void	rrr_sop(t_stack **a, t_stack **b, char *print);

// Parsing Functions
bool	valid_input(char **argv);
char	*join_args(char **argv);
t_stack	*string_to_stack(char **slitted);

// Cost Simulation Functions
void	update_cost(t_stack *a, t_stack *b, t_list *lis);
t_stack	*cheapest_node(t_stack *a);

// Solver Functions
int		find_index(t_stack *b, int value);
void	rr_sop_multi(t_stack **a, t_stack **b, int *indexa, int *indexb);
void	r_sop_multi(t_stack **a, t_stack **b, int *indexa, int *indexb);
void	rotation_judge_a2b(t_stack **a, t_stack **b, int indexa, int indexb);
int		is_in_the_lis_list(t_list *lis, int *val);

#endif
