/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 19:37:30 by mkhemakh          #+#    #+#             */
/*   Updated: 2021/07/05 18:34:07 by mkhemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstremove(t_list **lst)
{
	t_list	*temporary;

	if (!lst)
		return ;
	temporary = *lst;
	*lst = temporary->next;
	temporary->next = NULL;
	free(temporary);
}
