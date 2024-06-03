/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:44:37 by sforster          #+#    #+#             */
/*   Updated: 2024/06/03 14:15:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_b_to_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*cur_a;
	int			min;

	cur_a = *stack_a;
	min = cur_a->num;
	if ((*stack_b)->num < min)
	{
		back_a_smaller(stack_a, stack_b);
		return ;
	}
	stack_b_to_stack_a_2(stack_a, stack_b);
	return ;
}

void	stack_b_to_stack_a_2(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*cur_a;
	int			min;
	int			middle;
	int			max;

	cur_a = *stack_a;
	min = cur_a->num;
	middle = cur_a->next->num;
	max = cur_a->next->next->num;
	cur_a = *stack_a;
	while ((*stack_b) != NULL && (*stack_b)->num > max)
		push_a(stack_a, stack_b);
	rra(stack_a);
	while ((*stack_b) != NULL && (*stack_b)->num > middle)
		push_a(stack_a, stack_b);
	rra(stack_a);
	while ((*stack_b) != NULL && (*stack_b)->num > min)
		push_a(stack_a, stack_b);
	rra(stack_a);
	while ((*stack_b) != NULL)
		push_a(stack_a, stack_b);
	return ;
}

void	back_a_smaller(t_stack **stack_a, t_stack **stack_b)
{
	while ((*stack_b) != NULL)
		push_a(stack_a, stack_b);
	return ;
}

void	top_b(t_stack **stack_b)
{
	t_stack		*b_min;
	int			to_up;
	int			to_down;

	b_min = max_node(stack_b);
	to_up = b_min->index;
	to_down = stack_len(*stack_b) - b_min->index;
	if (to_up < to_down)
	{
		while (to_up > 0)
		{
			rb(stack_b);
			to_up--;
		}
	}
	else
	{
		while (to_down > 0)
		{
			rrb(stack_b);
			to_down--;
		}
	}
	free (b_min);
	return ;
}

/*
void	stack_b_to_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*cur_a;
	int			min;
	int			middle;
	int			max;

	cur_a = *stack_a;
	min = cur_a->num;
	middle = cur_a->next->num;
	max = cur_a->next->next->num;
	if ((*stack_b)->num < min)
	{
		back_a_smaller(stack_a, stack_b);
		return ;
	}
	cur_a = *stack_a;
	while ((*stack_b) != NULL && (*stack_b)->num > max)
		push_a(stack_a, stack_b);
	rra(stack_a);
	while ((*stack_b) != NULL && (*stack_b)->num > middle)
		push_a(stack_a, stack_b);
	rra(stack_a);
	while ((*stack_b) != NULL && (*stack_b)->num > min)
		push_a(stack_a, stack_b);
	rra(stack_a);
	while ((*stack_b) != NULL)
		push_a(stack_a, stack_b);
	return ;
}
*/