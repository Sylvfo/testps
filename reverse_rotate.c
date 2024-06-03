/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:42:42 by sforster          #+#    #+#             */
/*   Updated: 2024/05/30 13:47:14 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// vers le bas
void	rev_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*bottom;
	t_stack	*current;

	current = *stack;
	bottom = *stack;
	head = *stack;
	while (current->next->next != NULL)
	{
		current = current->next;
	}
	bottom = current->next;
	*stack = bottom;
	bottom->next = head;
	head->prev = bottom;
	bottom->prev = NULL;
	current->next = NULL;
	return ;
}

void	rra(t_stack **stack_a)
{
	if (*stack_a == NULL)
		return ;
	if ((*stack_a)->next == NULL)
		return ;
	rev_rotate(stack_a);
	ft_printf("rra\n");
	return ;
}

void	rrb(t_stack **stack_b)
{
	if (*stack_b == NULL)
		return ;
	if ((*stack_b)->next == NULL)
		return ;
	rev_rotate(stack_b);
	ft_printf("rrb\n");
	return ;
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a == NULL || *stack_b == NULL)
		return ;
	if ((*stack_a)->next == NULL || (*stack_b)->next == NULL)
		return ;
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_printf("rrr\n");
	return ;
}
