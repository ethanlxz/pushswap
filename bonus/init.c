/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:52:59 by etlaw             #+#    #+#             */
/*   Updated: 2023/06/20 21:57:13 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	fill_stack(char **input, t_stack **stack_a)
{
	*stack_a = fill_stack_value(input);
	return ;
}
