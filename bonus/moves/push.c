/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 21:28:47 by etlaw             #+#    #+#             */
/*   Updated: 2023/06/22 23:00:18 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	push(t_stack **src, t_stack **desc)
{
	t_stack	*tmp;

	tmp = (*src)->next;
	(*src)->next = *desc;
	*desc = *src;
	*src = tmp;
}

void	do_pa(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b == NULL)
		return ;
	push(stack_b, stack_a);
}

void	do_pb(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a == NULL)
		return ;
	push(stack_a, stack_b);
}
