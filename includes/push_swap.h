/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhemakh <mkhemakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 21:40:15 by mkhemakh          #+#    #+#             */
/*   Updated: 2021/08/25 15:47:53 by mkhemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "utils.h"

# ifndef MAX_SIZE
#  define MAX_SIZE 20
# endif

void	start_sorting(t_stack **stack_a, t_stack **stack_b);
void	small_sorting(t_stack **stack_a);
void	medium_sorting(t_stack **stack_a, t_stack **stack_b);
void	big_sorting(t_stack **stack_a, t_stack **stack_b,
			t_stack **limits, int i);
void	push_min_to_b(t_stack **stack_a, t_stack **stack_b);
void	get_new_limit(t_stack **limits, t_stack *stack, int status);
int		get_hold_first(t_stack *stack_a, t_stack *limits);
int		get_hold_second(t_stack *stack_a, t_stack *limits);
void	split_a_to_b(t_stack **stack_a, t_stack **stack_b, t_stack *limits);
void	merge_half_to_a(t_stack **stack_a, t_stack **stack_b, t_stack *limits);
void	merge_sort_to_a(t_stack **stack_a, t_stack **stack_b, t_stack *limits);
void	rotate_until_sorted(t_stack **stack_a, t_stack *limits);
int		count_in_between(t_stack *stack_a, t_stack *limits);
int		get_next_value(t_stack *stack_a, t_stack **limits);

#endif
