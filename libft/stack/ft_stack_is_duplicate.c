/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_is_duplicate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:30:46 by mkhemakh          #+#    #+#             */
/*   Updated: 2021/07/30 17:28:28 by mkhemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_stack_is_duplicate(t_stack *stack)
{
	t_stack	*sorted;

	sorted = ft_stack_duplicate(stack);
	ft_stack_sort(&sorted);
	while (sorted->next)
	{
		if (sorted->data == sorted->next->data)
			return (1);
		sorted = sorted->next;
	}
	ft_stack_clear(&sorted);
	return (0);
}
