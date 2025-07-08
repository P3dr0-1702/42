/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_func.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:45:31 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/08 18:53:37 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUX_FUNC_H
# define AUX_FUNC_H

# include "libft/libft.h"

// Array Manipulation
int		*stack_to_arr_conversion(t_stack *stack);
int		fill_prev(int *prev, int *tails, int start, int i);
int		fill_arr(int *arr, int *tails, int *prev, int size);

// Auxiliary Functions
int		abs(int x);
void	print_stack(t_stack **a);
void	print_list(t_list **a);
int		is_stack_solved(t_stack *a, int is_reverse);
int		last_val(t_stack *a);
char	*limits(int sign);

// Cleaner
void	free_stack(t_stack *stack);
void	free_list(t_list *list);
void	free_arr(void **arr);

// Indexer
void	indexer(t_stack **a2, t_stack **solved);

// Input Validation
bool	has_dulicate(t_stack *stack);
bool	is_alldigit(char *s);
bool	is_valid_input(char **argv);
bool	within_bounds(char **str);

// Lazy Mover
int		get_node_index(t_stack *a, t_stack *target);
void	move_cheapest(t_stack **a, t_stack **b, t_list *lis);
int		notmembers_of_lis(t_stack *a, t_list *lis);

// LIS List Functions
t_list	*lis_tractor(t_stack *stack);
t_list	*list_lis(t_stack *stack);

// Parsing Function
int		arr_len(char **ar);
char	*join_args(char **argv);
t_stack	*string_to_stack(char **slitted);

// Push Swap Operations
void	s_op(t_stack **lst, char is_a);
void	p_op(t_stack **from, t_stack **to, char is_a);
void	r_op(t_stack **a, char is_a);
void	rr_op(t_stack **a, char is_a);

// Push Swap Simultaneous Operations
void	ss_sop(t_stack **a, t_stack **b);
void	rr_sop(t_stack **a, t_stack **b, char *print);
void	rrr_sop(t_stack **a, t_stack **b, char *print);

//Quick Solve
void	quick_solve(t_stack *a);

// Rotation Judge
void	rr_sop_multi(t_stack **a, t_stack **b, int *indexa, int *indexb);
void	r_sop_multi(t_stack **a, t_stack **b, int *indexa, int *indexb);
void	rotation_judge(t_stack **a, t_stack **b, int indexa, int indexb);
void	rotation_judge_nopush(t_stack **a, t_stack **b, int indexa, int indexb);

// Rotator Functions
int		rotate_to_min(t_stack *target);
int		rotate_to_max(t_stack *s);
void	rotate_to_extremes(t_stack **a, t_stack **b, t_list *lis);

// Cost Simulation Functions
int		sim_rotation_judge(t_stack *b, int index);
void	update_cost(t_stack *a, t_stack *b, t_list *lis);
t_stack	*cheapest_node(t_stack *a);

// Solver
int		find_index(t_stack *b, int value);
int		is_in_the_lis_list(t_list *lis, int *val);
void	all_to_a(t_stack **a, t_stack **b);
void	solver(t_stack *a, t_stack *b, t_list *lis);

// Stack Solver
t_stack	*stack_solver(t_stack **a);
t_stack	*put_into_stack(t_stack *sorted, t_stack *node);
t_stack	*ft_stack_newnode(int currNBR);

#endif
