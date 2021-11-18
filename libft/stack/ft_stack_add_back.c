/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_add_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 06:35:30 by mkhemakh          #+#    #+#             */
/*   Updated: 2021/08/19 15:58:48 by mkhemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!*stack)
		*stack = new;
	else
	{
		last = ft_stack_last(*stack);
		new->previous = last;
		last->next = new;
	}
}
