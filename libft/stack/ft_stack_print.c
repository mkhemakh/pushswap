/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 15:24:00 by mkhemakh          #+#    #+#             */
/*   Updated: 2021/08/09 20:03:05 by mkhemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stack_print(t_stack *stack)
{
	t_stack	*temporary;

	if (!stack)
		return ;
	temporary = stack;
	while (temporary)
	{
		ft_putnbr_fd(temporary->data, 1);
		if (temporary->next)
			ft_putstr_fd(", ", 1);
		else
			ft_putstr_fd("\n", 1);
		temporary = temporary->next;
	}
}
