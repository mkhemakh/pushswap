/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_median.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:42:01 by mkhemakh          #+#    #+#             */
/*   Updated: 2021/08/09 15:45:54 by mkhemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	ft_stack_median(t_stack *stack)
{
	t_stack	*duplicate;
	int		half;

	half = ft_stack_size(stack) / 2;
	duplicate = ft_stack_duplicate(stack);
	ft_stack_sort(&duplicate);
	return (ft_stack_get(duplicate, half - 1));
}
