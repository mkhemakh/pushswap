/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhemakh <mkhemakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 13:38:08 by mkhemakh          #+#    #+#             */
/*   Updated: 2021/09/25 21:34:53 by mkhemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "get_next_line.h"
# include "utils.h"

int		get_instructions(t_list **instructions);
int		instruction_cmp(char *line);
void	implement_instruction(t_stack **stack_a, t_stack **stack_b,
			char *instruction);
void	exe_instruction(t_stack **stack_a, t_stack **stack_b,
			t_list	*instructions,
			char mode);
void	exit_checker(t_stack *stack_a, t_stack *stack_b, t_list **instructions,
			int status);
void	print_both_stacks(t_stack *stack_a, t_stack *stack_b, char *message);

#endif
