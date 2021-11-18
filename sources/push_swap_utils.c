/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhemakh <mkhemakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 19:07:13 by mkhemakh          #+#    #+#             */
/*   Updated: 2021/09/28 14:21:46 by mkhemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_min_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	minimum;

	minimum = ft_stack_min_value(*stack_a);
	while ((*stack_a)->data != minimum)
	{
		if ((*stack_a)->data != minimum && (*stack_a)->next->data != minimum)
			reverse_rotate_stack(stack_a, 0, "rra\n");
		else
			rotate_stack(stack_a, 0, "ra\n");
	}
	push_stack(stack_a, stack_b, "pb\n");
}

void	get_new_limit(t_stack **limits, t_stack *stack, int status)
{
	t_stack	*duplicate;
	int		min_idx;
	int		max_idx;
	int		new;

	duplicate = ft_stack_duplicate(stack);
	ft_stack_sort(&duplicate);
	if (status)
	{
		min_idx = ft_stack_find(duplicate, (*limits)->data);
		max_idx = ft_stack_find(duplicate, (*limits)->next->data);
		new = ft_stack_get(duplicate, ((max_idx - min_idx) / 2 + min_idx + 3));
	}
	else
		new = ft_stack_get(duplicate, ft_stack_size(duplicate) / 2);
	ft_stack_add_front(limits, ft_stack_new(new));
	ft_stack_sort(limits);
	ft_stack_clear(&duplicate);
}

int	get_hold_first(t_stack *stack_a, t_stack *limits)
{
	int	first;
	int	max;
	int	min;

	min = limits->data;
	max = limits->next->data;
	first = 0;
	while (stack_a)
	{
		if (stack_a->data >= min && stack_a->data <= max)
			return (first);
		first++;
		stack_a = stack_a->next;
	}
	return (first);
}

int	get_hold_second(t_stack *stack_a, t_stack *limits)
{
	int	second;
	int	max;
	int	min;

	stack_a = ft_stack_last(stack_a);
	min = limits->data;
	max = limits->next->data;
	second = 1;
	while (stack_a)
	{
		if (stack_a->data >= min && stack_a->data <= max)
			return (second);
		second++;
		stack_a = stack_a->previous;
	}
	return (second);
}

int	get_next_value(t_stack *stack_a, t_stack **limits)
{
	t_stack	*duplicate;
	int		position;
	int		minimum;

	duplicate = ft_stack_duplicate(stack_a);
	ft_stack_sort(&duplicate);
	position = ft_stack_find(duplicate, (*limits)->next->data);
	minimum = ft_stack_get(duplicate, position);
	if (minimum == ft_stack_last(duplicate)->data)
	{
		ft_stack_clear(&duplicate);
		return (minimum);
	}
	else
		minimum = ft_stack_get(duplicate, position + 1);
	ft_stack_clear(&duplicate);
	return (minimum);
}
