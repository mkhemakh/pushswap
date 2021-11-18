/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_has_bigger.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:24:21 by mkhemakh          #+#    #+#             */
/*   Updated: 2021/08/28 14:34:34 by mkhemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	ft_stack_has_bigger(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->data > value)
			return (1);
		stack = stack->next;
	}
	return (0);
}
