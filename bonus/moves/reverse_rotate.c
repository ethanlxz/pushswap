/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 21:40:21 by etlaw             #+#    #+#             */
/*   Updated: 2023/06/22 23:06:21 by etlaw            ###   ########.fr       */
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
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	rev_rotate(stack_a);
}

void	do_rrb(t_stack **stack_b)
{
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	rev_rotate(stack_b);
}

void	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	rev_rotate(stack_a);
	rev_rotate(stack_b);
}
