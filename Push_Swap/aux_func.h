/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_func.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:37:04 by pfreire-          #+#    #+#             */
/*   Updated: 2025/05/25 18:13:07 by pfreire-         ###   ########.fr       */
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
// operators
void	s_op(t_stack **lst, char is_a);
void	p_op(t_stack **b, t_stack **a, char is_a);
void	r_op(t_stack **a, char is_a);
void	rr_op(t_stack **a, char is_a);
void	ss_sop(t_stack **a, t_stack **b);
void	rr_sop(t_stack **a, t_stack **b);
void	rrr_sop(t_stack **a, t_stack **b);

#endif