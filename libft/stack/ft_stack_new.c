/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 16:03:31 by mkhemakh          #+#    #+#             */
/*   Updated: 2021/08/18 20:19:41 by mkhemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_stack_new(int data)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack) * 1);
	if (!stack)
		return (NULL);
	stack->data = data;
	stack->next = NULL;
	stack->previous = NULL;
	return (stack);
}
