/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_find.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:05:23 by mkhemakh          #+#    #+#             */
/*   Updated: 2021/06/02 14:16:20 by mkhemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	ft_stack_find(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (value == stack->data)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-2147483648);
}
