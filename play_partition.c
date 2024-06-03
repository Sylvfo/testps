/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_partition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:40:21 by sforster          #+#    #+#             */
/*   Updated: 2024/05/30 13:40:48 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	play_notes(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*node;

	node = *stack_a;
	while (node->cheapest != 2)
		node = node->next;
	if (node->push_cost == 0)
		return ;
	play_rrarrbrrr(node, stack_a, stack_b);
	play_rarbrr(node, stack_a, stack_b);
	return ;
}

void	play_rarbrr(t_stack *node, t_stack **stack_a, t_stack **stack_b)
{
	int			nra;
	int			nrb;
	int			nrr;

	nra = node->partition->ra;
	nrb = node->partition->rb;
	nrr = node->partition->rr;
	while (nra > 0)
	{
		ra(stack_a);
		nra--;
	}
	while (nrb > 0)
	{
		rb(stack_b);
		nrb--;
	}
	while (nrr > 0)
	{
		rr(stack_a, stack_b);
		nrr--;
	}
	return ;
}

void	play_rrarrbrrr(t_stack *node, t_stack **stack_a, t_stack **stack_b)
{
	int			nrra;
	int			nrrb;
	int			nrrr;

	nrra = node->partition->rra;
	nrrb = node->partition->rrb;
	nrrr = node->partition->rrr;
	while (nrra > 0)
	{
		rra(stack_a);
		nrra--;
	}
	while (nrrb > 0)
	{
		rrb(stack_b);
		nrrb--;
	}
	while (nrrr > 0)
	{
		rrr(stack_a, stack_b);
		nrrr--;
	}
	return ;
}
