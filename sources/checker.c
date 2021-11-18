/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhemakh <mkhemakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:18:16 by mkhemakh          #+#    #+#             */
/*   Updated: 2021/09/15 23:58:30 by mkhemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*instructions;
	char	mode;

	if (argc == 1 || (argc == 2 && !ft_strcmp("-v", argv[1])))
		exit(1);
	stack_a = 0;
	stack_b = 0;
	instructions = 0;
	mode = 0;
	if (!ft_strcmp("-v", argv[1]))
	{
		convert_to_stack(argc - 1, &argv[2], &stack_a);
		mode = 'v';
	}
	else
		convert_to_stack(argc, &argv[1], &stack_a);
	if (!(get_instructions(&instructions)))
		exit_checker(stack_a, 0, &instructions, 0);
	exe_instruction(&stack_a, &stack_b, instructions, mode);
	if (ft_stack_is_sorted(stack_a) && !stack_b)
		exit_checker(stack_a, stack_b, &instructions, 2);
	exit_checker(stack_a, stack_b, &instructions, 1);
	return (0);
}

int	get_instructions(t_list **instructions)
{
	char	*line;
	t_list	*new_node;

	line = NULL;
	new_node = 0;
	while (get_next_line(STDIN_FILENO, &line))
	{
		if (instruction_cmp(line) == 0)
		{
			free(line);
			return (0);
		}
		new_node = ft_lstnew(line);
		if (!new_node)
		{
			free(line);
			return (0);
		}
		ft_lstadd_back(instructions, new_node);
	}
	if (!instructions)
		return (0);
	free(line);
	return (1);
}

void	exe_instruction(t_stack **stack_a, t_stack **stack_b,
			t_list	*instructions, char mode)
{
	if (mode)
		print_both_stacks(*stack_a, *stack_b, "init");
	while (instructions)
	{
		implement_instruction(stack_a, stack_b,
			(char *)instructions->content);
		if (mode)
			print_both_stacks(*stack_a, *stack_b,
				(char *)instructions->content);
		instructions = instructions->next;
	}
}

void	implement_instruction(t_stack **stack_a, t_stack **stack_b,
			char *instruction)
{
	if (!ft_strcmp("sa", instruction))
		swap_stack(*stack_a, 0, 0);
	if (!ft_strcmp("sb", instruction))
		swap_stack(*stack_b, 0, 0);
	if (!ft_strcmp("ss", instruction))
		swap_stack(*stack_a, *stack_b, 0);
	if (!ft_strcmp("pa", instruction))
		push_stack(stack_b, stack_a, 0);
	if (!ft_strcmp("pb", instruction))
		push_stack(stack_a, stack_b, 0);
	if (!ft_strcmp("ra", instruction))
		rotate_stack(stack_a, 0, 0);
	if (!ft_strcmp("rb", instruction))
		rotate_stack(stack_b, 0, 0);
	if (!ft_strcmp("rr", instruction))
		rotate_stack(stack_a, stack_b, 0);
	if (!ft_strcmp("rra", instruction))
		reverse_rotate_stack(stack_a, 0, 0);
	if (!ft_strcmp("rrb", instruction))
		reverse_rotate_stack(stack_b, 0, 0);
	if (!ft_strcmp("rrr", instruction))
		reverse_rotate_stack(stack_a, stack_b, 0);
}

void	exit_checker(t_stack *stack_a, t_stack *stack_b, t_list **instructions,
			int status)
{
	if (stack_a)
		ft_stack_clear(&stack_a);
	if (stack_b)
		ft_stack_clear(&stack_b);
	if (*instructions)
	{
		while (*instructions)
		{
			free((*instructions)->content);
			ft_lstremove(instructions);
		}
	}
	if (!status)
		ft_putstr_fd("Error\n", 2);
	else if (status == 1)
		ft_putstr_fd("KO\n", 2);
	else if (status == 2)
	{
		ft_putstr_fd("OK\n", 1);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}
