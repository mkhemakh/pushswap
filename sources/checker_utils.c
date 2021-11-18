/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhemakh <mkhemakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 14:08:21 by mkhemakh          #+#    #+#             */
/*   Updated: 2021/09/28 17:46:45 by mkhemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

void	print_stacks(t_stack **stack_a, t_stack **stack_b, int *size_a,
		int *size_b)
{
	if (*size_a > *size_b && (*size_a)--)
	{
		printf("%-3d\n", (*stack_a)->data);
		(*stack_a) = (*stack_a)->next;
	}
	else if (*size_b > *size_a && (*size_b)--)
	{
		printf("        %-3d\n", (*stack_b)->data);
		(*stack_b) = (*stack_b)->next;
	}
	else if ((*size_a)-- && (*size_b)--)
	{
		printf("%-3d     %-3d\n", (*stack_a)->data, (*stack_b)->data);
		(*stack_a) = (*stack_a)->next;
		(*stack_b) = (*stack_b)->next;
	}
}

void	print_both_stacks(t_stack *stack_a, t_stack *stack_b, char *message)
{
	int	size_a;
	int	size_b;

	size_a = ft_stack_size(stack_a);
	size_b = ft_stack_size(stack_b);
	printf("------------\n%s:\n\n\n", message);
	while (size_a >= 0 && size_b >= 0)
		print_stacks(&stack_a, &stack_b, &size_a, &size_b);
	printf("___     ___\n a       b\n\n");
}

int	instruction_cmp(char *line)
{
	if (!(!ft_strcmp("sa", line) || !ft_strcmp("sb", line)
			 || !ft_strcmp("ss", line) || !ft_strcmp("pa", line)
			 || !ft_strcmp("pb", line) || !ft_strcmp("ra", line)
			 || !ft_strcmp("rb", line) || !ft_strcmp("rr", line)
			 || !ft_strcmp("rra", line) || !ft_strcmp("rrb", line)
			 || !ft_strcmp("rrr", line)))
		return (0);
	return (1);
}
