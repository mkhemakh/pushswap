/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhemakh <mkhemakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:01:52 by mkhemakh          #+#    #+#             */
/*   Updated: 2021/09/27 18:34:23 by mkhemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	convert_error(char **str, t_stack **stack_a, int i)
{
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
	free(str);
	exit_push_swap(*stack_a, 0, 0);
}

void	convert_to_stack1(char **numbers, t_stack **stack_a)
{
	int			i;
	long int	data;
	t_stack		*new_node;

	i = 0;
	while (numbers[i])
	{
		if (!ft_str_isnumeric(numbers[i]))
			convert_error(numbers, stack_a, i);
		data = ft_atoi(numbers[i]);
		free(numbers[i]);
		new_node = ft_stack_new(data);
		if (!new_node || !ft_isint(data))
		{
			ft_stack_remove(&new_node);
			convert_error(numbers, stack_a, ++i);
		}
		ft_stack_add_back(stack_a, new_node);
		i++;
	}
	free(numbers);
	if (ft_stack_is_duplicate(*stack_a))
		exit_push_swap(*stack_a, 0, 0);
}

void	convert_to_stack2(char **argv, t_stack **stack_a)
{
	int			i;
	long int	data;
	t_stack		*new_node;

	i = 0;
	while (argv[i])
	{
		if (!ft_str_isnumeric(argv[i]))
			exit_push_swap(*stack_a, 0, 0);
		data = ft_atoi(argv[i]);
		if (!ft_isint(data))
			exit_push_swap(*stack_a, 0, 0);
		new_node = ft_stack_new(data);
		if (!new_node)
			exit_push_swap(*stack_a, 0, 0);
		ft_stack_add_back(stack_a, new_node);
		i++;
	}
	if (ft_stack_is_duplicate(*stack_a))
		exit_push_swap(*stack_a, 0, 0);
}

void	convert_to_stack(int ac, char **argv, t_stack **stack_a)
{
	int		i;
	char	**numbers;

	i = -1;
	while (argv[++i])
		if (ft_strlen(argv[i]) == 0)
			exit_push_swap(*stack_a, 0, 0);
	if (ac == 2 && !ft_str_isnumeric(argv[0]))
	{
		numbers = ft_split(argv[0], ' ');
		convert_to_stack1(numbers, stack_a);
	}
	if (ac >= 2 && ft_str_isnumeric(argv[0]))
		convert_to_stack2(argv, stack_a);
	if (ac > 2 && !ft_str_isnumeric(argv[0]))
		exit_push_swap(*stack_a, 0, 0);
}

void	exit_push_swap(t_stack *stack_a, t_stack *stack_b, int status)
{
	if (stack_a)
		ft_stack_clear(&stack_a);
	if (stack_b)
		ft_stack_clear(&stack_b);
	if (!status)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
