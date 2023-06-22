/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:17:45 by etlaw             #+#    #+#             */
/*   Updated: 2023/06/21 22:45:56 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
		{
			write(1, "KO\n", 3);
			return ;
		}
		stack = stack->next;
	}
	write(1, "OK\n", 3);
	return ;
}

void	rrr_or_die(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (!ft_strcmp(str, "rra\n"))
		do_rra(stack_a);
	else if (!ft_strcmp(str, "rrb\n"))
		do_rrb(stack_b);
	else if (!ft_strcmp(str, "rrr\n"))
		do_rrr(stack_a, stack_b);
	else
		errormsg("Error\n");
}

void	do_sort(t_stack **stack_a, t_stack **stack_b, char *str)
{
	while (str != NULL)
	{
		if (!ft_strcmp(str, "sa\n"))
			do_sa(stack_a);
		else if (!ft_strcmp(str, "sb\n"))
			do_sb(stack_b);
		else if (!ft_strcmp(str, "ss\n"))
			do_ss(stack_a, stack_b);
		else if (!ft_strcmp(str, "pa\n"))
			do_pa(stack_a, stack_b);
		else if (!ft_strcmp(str, "pb\n"))
			do_pb(stack_a, stack_b);
		else if (!ft_strcmp(str, "ra\n"))
			do_ra(stack_a);
		else if (!ft_strcmp(str, "rb\n"))
			do_rb(stack_b);
		else if (!ft_strcmp(str, "rr\n"))
			do_rr(stack_a, stack_b);
		else
			rrr_or_die(stack_a, stack_b, str);
		str = get_next_line(0);
	}
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("num is %i\n", stack->value);
		stack = stack->next;
	}
	return ;
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*str;
	char	**input;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	else
	{
		input = get_crt_input(ac, av);
		fill_stack(input, &stack_a);
	}
	str = get_next_line(0);
	do_sort(&stack_a, &stack_b, str);
	check_sorted(stack_a);
	return (0);
}
