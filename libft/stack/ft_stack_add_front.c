/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_add_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 16:15:34 by mkhemakh          #+#    #+#             */
/*   Updated: 2021/08/21 16:23:30 by mkhemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stack_add_front(t_stack **stack, t_stack *new)
{
	t_stack	*temporary;

	temporary = *stack;
	if (temporary)
	{
		new->next = temporary;
		temporary->previous = new;
	}
	*stack = new;
}
