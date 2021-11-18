/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhemakh <mkhemakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 19:12:09 by mkhemakh          #+#    #+#             */
/*   Updated: 2021/09/20 14:51:55 by mkhemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"

void	convert_to_stack(int ac, char **argv, t_stack **stack_a);
void	exit_push_swap(t_stack *stack_a, t_stack *stack_b, int status);
void	swap_stack(t_stack *mandatory, t_stack *optional, char *message);
void	push_stack(t_stack **from_stack, t_stack **to_stack, char *message);
void	rotate_stack(t_stack **mandatory, t_stack **optional, char *message);
void	reverse_rotate_stack(t_stack **mandatory,
			t_stack **optional, char *message);

#endif
