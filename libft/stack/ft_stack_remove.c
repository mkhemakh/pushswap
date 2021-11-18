/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_remove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 18:16:42 by mkhemakh          #+#    #+#             */
/*   Updated: 2021/08/05 18:26:34 by mkhemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stack_remove(t_stack **stack)
{
	t_stack	*temporary;

	if (!stack)
		return ;
	temporary = *stack;
	if (temporary->next)
		temporary->next->previous = temporary->previous;
	if (temporary->previous)
		temporary->previous->next = temporary->next;
	if (temporary->previous)
		*stack = temporary->previous;
	else
		*stack = temporary->next;
	free(temporary);
}
