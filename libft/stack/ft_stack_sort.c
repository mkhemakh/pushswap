/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 22:13:10 by mkhemakh          #+#    #+#             */
/*   Updated: 2021/08/08 13:32:55 by mkhemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stack_sort(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	first = *stack;
	if (!first || !first->next)
		return ;
	second = ft_stack_split(first);
	ft_stack_sort(&first);
	ft_stack_sort(&second);
	*stack = ft_merge_sort(first, second);
}

t_stack	*ft_merge_sort(t_stack *first, t_stack *second)
{
	if (!first)
		return (second);
	if (!second)
		return (first);
	if (first->data < second->data)
	{
		first->next = ft_merge_sort(first->next, second);
		first->next->previous = first;
		first->previous = 0;
		return (first);
	}
	else
	{
		second->next = ft_merge_sort(first, second->next);
		second->next->previous = second;
		second->previous = 0;
		return (second);
	}
}

t_stack	*ft_stack_split(t_stack	*head)
{
	t_stack	*slow;
	t_stack	*fast;
	t_stack	*temporary;

	slow = head;
	fast = head;
	while (fast->next && fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	temporary = slow->next;
	slow->next = 0;
	return (temporary);
}
