/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_min_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:29:25 by mkhemakh          #+#    #+#             */
/*   Updated: 2021/08/20 11:31:40 by mkhemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_stack_min_value(t_stack *stack_a)
{
	int	min_value;

	min_value = stack_a->data;
	while (stack_a)
	{
		if (stack_a->data < min_value)
			min_value = stack_a->data;
		stack_a = stack_a->next;
	}
	return (min_value);
}
