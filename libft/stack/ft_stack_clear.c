/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:04:07 by mkhemakh          #+#    #+#             */
/*   Updated: 2021/08/18 15:38:44 by mkhemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stack_clear(t_stack **stack)
{
	if (!stack)
		return ;
	while (*stack)
		ft_stack_remove(stack);
}
