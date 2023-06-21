/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 21:40:21 by etlaw             #+#    #+#             */
/*   Updated: 2023/06/20 22:26:17 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*tail;
	t_stack	*before_tail;

	tail = get_stack_bottom(*stack);
	before_tail = get_stack_before_bottom(*stack);
	tail->next = *stack;
	*stack = tail;
	before_tail->next = NULL;
}

void	do_rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
}

void	do_rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
}

void	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
}