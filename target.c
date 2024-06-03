/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:47:29 by sforster          #+#    #+#             */
/*   Updated: 2024/06/03 14:03:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target_nodes(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cur_a;
	t_stack	*cur_b;
	t_stack	*minb;
	t_stack	*maxb;

	minb = min_node(stack_b);
	maxb = max_node(stack_b);
	above_med(stack_b, maxb);
	cur_a = *stack_a;
	while (cur_a != NULL)
	{
		cur_b = *stack_b;
		if (cur_a->num < minb->num || cur_a->num > maxb->num)
			target_max(cur_a, cur_b, maxb);
		else if (cur_b->above_median != 5)
			target_up_median(cur_a, cur_b);
		else
			target_to_median(cur_a, cur_b, stack_b);
		cur_a = cur_a->next;
	}
	free (minb);
	free (maxb);
	return ;
}

void	target_max(t_stack *cur_a, t_stack *cur_b, t_stack *maxb)
{
	while (cur_b != NULL && cur_b->num < maxb->num)
		cur_b = cur_b->next;
	cur_a->target_node = cur_b;
	return ;
}

void	target_up_median(t_stack *cur_a, t_stack *cur_b)
{
	while (cur_b != NULL && cur_a->num < cur_b->num)
		cur_b = cur_b->next;
	cur_a->target_node = cur_b;
	return ;
}

void	target_to_median(t_stack *cur_a, t_stack *cur_b, t_stack **stack_b)
{
	t_stack	*lst;

	lst = *stack_b;
	while (lst->next != NULL)
		lst = lst->next;
	if (cur_a->num < lst->num)
	{
		while (cur_a->num < cur_b->num && cur_b != NULL)
			cur_b = cur_b->next;
		cur_a->target_node = cur_b;
	}
	else
	{
		while (cur_b->above_median == 5)
			cur_b = cur_b->next;
		while (cur_a->num < cur_b->num && cur_b != NULL)
			cur_b = cur_b->next;
		cur_a->target_node = cur_b;
	}
	return ;
}

void	above_med(t_stack **stack_b, t_stack *maxb)
{
	t_stack	*current;

	current = *stack_b;
	if (maxb->index == 0)
	{
		while (current != NULL)
		{
			current->above_median = 0;
			current = current->next;
		}
	}
	else
	{
		while (current != NULL && current->index < maxb->index)
		{
			current->above_median = 5;
			current = current->next;
		}
	}
	return ;
}
