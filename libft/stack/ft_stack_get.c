/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 11:12:16 by mkhemakh          #+#    #+#             */
/*   Updated: 2021/07/24 10:15:09 by mkhemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	ft_stack_get(t_stack *stack, int position)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (i == position)
			return (stack->data);
		stack = stack->next;
		i++;
	}
	return (-2147483648);
}
