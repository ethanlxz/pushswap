/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:52:59 by etlaw             #+#    #+#             */
/*   Updated: 2023/04/27 19:11:36 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static t_stack	*fill_stack_value(char **input)
{
	t_stack	*stack_a;
	int		num;
	int		i;

	stack_a = NULL;
	i = 0;
	while (input[i])
	{
		num = ft_atoi(input[i]);
		if (i == 0)
			stack_a = stack_new(num);
		else
			stack_add_bottom(&stack_a, stack_new(num));
		i++;
	}
	return (stack_a);
}

static void	assign_index(t_stack *stack_a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		value = -2147483648;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == -2147483648 && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}

int	count_stack(char **input)
{
	int	size;

	size = 0;
	while (input[size])
		size++;
	return (size);
}

void	fill_stack(char **input, t_stack **stack_a)
{
	int	stack_size;

	stack_size = count_stack(input);
	*stack_a = fill_stack_value(input);
	assign_index(*stack_a, stack_size + 1);
	return ;
}
