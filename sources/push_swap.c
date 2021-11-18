/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhemakh <mkhemakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:46:38 by mkhemakh          #+#    #+#             */
/*   Updated: 2021/07/05 17:25:08 by mkhemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		exit(1);
	stack_a = 0;
	stack_b = 0;
	convert_to_stack(argc, &argv[1], &stack_a);
	if (!ft_stack_is_sorted(stack_a))
		start_sorting(&stack_a, &stack_b);
	exit_push_swap(stack_a, stack_b, 1);
	return (0);
}

void	start_sorting(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*limits;
	int		maximum;
	int		minimum;

	maximum = ft_stack_max_value(*stack_a);
	minimum = ft_stack_min_value(*stack_a);
	if (ft_stack_size(*stack_a) <= 3)
		small_sorting(stack_a);
	else if (ft_stack_size(*stack_a) <= 6)
		medium_sorting(stack_a, stack_b);
	else
	{
		limits = ft_stack_new(minimum);
		ft_stack_add_back(&limits, ft_stack_new(maximum));
		big_sorting(stack_a, stack_b, &limits, 0);
	}
}

void	small_sorting(t_stack **stack_a)
{
	int	maximum;
	int	minimum;

	maximum = ft_stack_max_value(*stack_a);
	minimum = ft_stack_min_value(*stack_a);
	while (!ft_stack_is_sorted(*stack_a))
	{
		if ((*stack_a)->data != minimum
			&& (*stack_a)->next->data == maximum)
			reverse_rotate_stack(stack_a, 0, "rra\n");
		else if ((*stack_a)->data == maximum
			&& (*stack_a)->next->data == minimum)
			rotate_stack(stack_a, 0, "ra\n");
		else
			swap_stack(*stack_a, 0, "sa\n");
	}
}

void	medium_sorting(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_stack_size(*stack_a) > 3)
		push_min_to_b(stack_a, stack_b);
	small_sorting(stack_a);
	while (ft_stack_size(*stack_b))
		push_stack(stack_b, stack_a, "pa\n");
}

void	big_sorting(t_stack **stack_a, t_stack **stack_b,
		t_stack **limits, int i)
{
	if (ft_stack_size(*limits) == 1)
	{
		ft_stack_clear(limits);
		return ;
	}
	if (ft_stack_size(*limits) == 2
		&& count_in_between(*stack_a, *limits) >= MAX_SIZE)
		get_new_limit(limits, *stack_a, 1);
	if (!ft_stack_size(*stack_b))
	{
		split_a_to_b(stack_a, stack_b, *limits);
		rotate_until_sorted(stack_a, *limits);
	}
	if (ft_stack_size(*stack_b) >= MAX_SIZE)
		merge_half_to_a(stack_a, stack_b, *limits);
	else
	{
		merge_sort_to_a(stack_a, stack_b, *limits);
		ft_stack_remove(limits);
	}
	big_sorting(stack_a, stack_b, limits, ++i);
}
