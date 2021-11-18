/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhemakh <mkhemakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 04:36:15 by mkhemakh          #+#    #+#             */
/*   Updated: 2021/09/25 22:42:17 by mkhemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_a_to_b(t_stack **stack_a, t_stack **stack_b, t_stack *limits)
{
	int	size;
	int	first;

	size = count_in_between(*stack_a, limits);
	while (ft_stack_size(*stack_b) < size)
	{
		first = get_hold_first(*stack_a, limits);
		while (first--)
			rotate_stack(stack_a, 0, "ra\n");
		push_stack(stack_a, stack_b, "pb\n");
	}
}

void	merge_half_to_a(t_stack **stack_a, t_stack **stack_b, t_stack *limits)
{
	get_new_limit(&limits, *stack_b, 0);
	while (ft_stack_has_bigger(*stack_b, limits->next->data))
	{
		if ((*stack_b)->data == ft_stack_min_value(*stack_b))
		{
			push_stack(stack_b, stack_a, "pa\n");
			if ((*stack_b)->data != ft_stack_min_value(*stack_b)
				&& (*stack_b)->data <= limits->next->data)
				rotate_stack(stack_a, stack_b, "rr\n");
			else
				rotate_stack(stack_a, 0, "ra\n");
		}
		else if ((*stack_b)->data > limits->next->data)
			push_stack(stack_b, stack_a, "pa\n");
		else
			rotate_stack(stack_b, 0, "rb\n");
	}
}

void	merge_sort_to_a(t_stack **stack_a, t_stack **stack_b, t_stack *limits)
{
	t_stack	*duplicate;

	duplicate = ft_stack_duplicate(*stack_b);
	ft_stack_sort(&duplicate);
	while (ft_stack_size(*stack_b))
	{
		if ((*stack_b)->data == duplicate->data)
		{
			push_stack(stack_b, stack_a, "pa\n");
			duplicate = duplicate->next;
			 if (ft_stack_size(*stack_b) && (*stack_b)->data != duplicate->data
				&& (*stack_b)->data != ft_stack_max_value(*stack_b))
				rotate_stack(stack_a, stack_b, "rr\n");
			else
				rotate_stack(stack_a, 0, "ra\n");
		}
		else if ((*stack_b)->data == ft_stack_max_value(*stack_b))
			push_stack(stack_b, stack_a, "pa\n");
		else
			rotate_stack(stack_b, 0, "rb\n");
	}
	while (ft_stack_last(*stack_a)->data != limits->next->data)
		rotate_stack(stack_a, 0, "ra\n");
	limits->next->data = get_next_value(*stack_a, &limits);
	ft_stack_clear(&duplicate);
}

void	rotate_until_sorted(t_stack **stack_a, t_stack *limits)
{
	t_stack	*duplicate;
	int		num;
	int		i;

	duplicate = ft_stack_duplicate(*stack_a);
	ft_stack_add_front(&duplicate, ft_stack_new(limits->data));
	ft_stack_sort(&duplicate);
	num = ft_stack_get(duplicate, ft_stack_find(duplicate, limits->data) - 1);
	ft_stack_clear(&duplicate);
	i = ft_stack_find(*stack_a, num);
	if (num == -2147483648 || i == -2147483648)
		return ;
	if (i <= ft_stack_size(*stack_a) / 2)
		while (ft_stack_last(*stack_a)->data != num)
			rotate_stack(stack_a, 0, "ra\n");
	else
		while (ft_stack_last(*stack_a)->data != num)
			reverse_rotate_stack(stack_a, 0, "rra\n");
}

int	count_in_between(t_stack *stack_a, t_stack *limits)
{
	t_stack	*duplicate;
	int		max_i;
	int		min_i;

	duplicate = ft_stack_duplicate(stack_a);
	ft_stack_sort(&duplicate);
	min_i = ft_stack_find(duplicate, limits->data);
	max_i = ft_stack_find(duplicate, limits->next->data);
	ft_stack_clear(&duplicate);
	return (max_i - min_i + 1);
}
