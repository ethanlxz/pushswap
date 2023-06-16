/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:26:02 by etlaw             #+#    #+#             */
/*   Updated: 2023/06/15 19:18:18 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	print_stack(t_stack *stack)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	tmp = stack;
	while (stack)
	{
		ft_printf("%ith num is %i|\n", stack->index, stack->value);
		stack = stack->next;
		i++;
	}
	stack = tmp;
}

static void	sort(t_stack **stack_a, t_stack **stack_b, char **input)
{
	int	stack_size;

	stack_size = count_stack(input);
	if (stack_size == 2 && !is_sorted(*stack_a))
		do_sa(stack_a);
	else if (stack_size == 3 && !is_sorted(*stack_a))
		tiny_sort(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
	{
		big_sort(stack_a, stack_b, stack_size);
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	char	**input;
	t_stack	*stack_b;

	if (ac > 1)
	{
		stack_a = NULL;
		stack_b = NULL;
		input = get_crt_input(ac, av);
		fill_stack(input, &stack_a);
		sort(&stack_a, &stack_b, input);
	}
	else
		ft_printf("\033[0;31mError : Too less arguments\n\033[42m");
	return (0);
}
