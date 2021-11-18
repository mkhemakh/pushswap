/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_max_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 08:25:50 by mkhemakh          #+#    #+#             */
/*   Updated: 2021/07/20 11:28:41 by mkhemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_stack_max_value(t_stack *stack_a)
{
	int	max_value;

	max_value = stack_a->data;
	while (stack_a)
	{
		if (stack_a->data > max_value)
			max_value = stack_a->data;
		stack_a = stack_a->next;
	}
	return (max_value);
}
