/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_four_to_six.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:35:56 by sforster          #+#    #+#             */
/*   Updated: 2024/05/30 13:36:17 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_four_six(t_stack **stack_a, t_stack **stack_b, int len)
{
	if (len == 4)
	{
		push_b(stack_a, stack_b);
	}
	if (len == 5)
	{
		push_b(stack_a, stack_b);
		push_b(stack_a, stack_b);
		sort_two_b(stack_b);
	}
	if (len == 6)
	{
		push_b(stack_a, stack_b);
		push_b(stack_a, stack_b);
		push_b(stack_a, stack_b);
		re_index_ab(stack_a, stack_b);
		sort_three_b(stack_b);
	}
	return ;
}

void	sort_two_b(t_stack **stack_b)
{
	if ((*stack_b)->num < (*stack_b)->next->num)
		sb(stack_b);
	return ;
}

void	sort_three_b(t_stack **head)
{
	t_stack	*min;
	t_stack	*max;

	min = min_node(head);
	max = max_node(head);
	if (min->index == 0 && max->index == 2)
	{
		sb(head);
		rrb(head);
	}
	if (min->index == 0 && max->index == 1)
		rb(head);
	if (min->index == 1 && max->index == 2)
		rrb(head);
	if (min->index == 2 && max->index == 1)
		sb(head);
	if (min->index == 1 && max->index == 0)
	{
		sb(head);
		rb(head);
	}
	free (min);
	free (max);
	return ;
}
