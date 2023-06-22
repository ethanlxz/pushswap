/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:58:59 by etlaw             #+#    #+#             */
/*   Updated: 2023/06/22 23:03:45 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = get_stack_bottom(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

void	do_ra(t_stack **stack_a)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	rotate(stack_a);
}

void	do_rb(t_stack **stack_b)
{
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	rotate(stack_b);
}

void	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	rotate(stack_a);
	rotate(stack_b);
}
