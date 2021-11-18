/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_duplicate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:48:23 by mkhemakh          #+#    #+#             */
/*   Updated: 2021/08/16 16:21:53 by mkhemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_stack	*ft_stack_duplicate(t_stack *stack)
{
	t_stack	*duplicate;
	t_stack	*new_node;

	duplicate = 0;
	while (stack)
	{
		new_node = ft_stack_new(stack->data);
		if (!new_node)
		{
			ft_stack_clear(&duplicate);
			return (0);
		}
		ft_stack_add_back(&duplicate, new_node);
		stack = stack->next;
	}
	return (duplicate);
}
