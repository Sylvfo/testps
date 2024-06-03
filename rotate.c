/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:43:19 by sforster          #+#    #+#             */
/*   Updated: 2024/05/30 13:44:17 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// vers le haut
void	rotate_a(t_stack **stack_a)
{
	t_stack	*head;
	t_stack	*current;

	head = *stack_a;
	current = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a != NULL)
		(*stack_a)->prev = NULL;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = head;
	head->prev = current;
	head->next = NULL;
	return ;
}

void	ra(t_stack **stack_a)
{
	if (*stack_a == NULL)
		return ;
	if ((*stack_a)->next == NULL)
		return ;
	rotate_a(stack_a);
	ft_printf("ra\n");
}

void	rotate_b(t_stack **stack_b)
{
	t_stack	*head;
	t_stack	*current;

	head = *stack_b;
	current = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_b != NULL)
		(*stack_b)->prev = NULL;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = head;
	head->prev = current;
	head->next = NULL;
	return ;
}

void	rb(t_stack **stack_b)
{
	if (*stack_b == NULL)
		return ;
	if ((*stack_b)->next == NULL)
		return ;
	rotate_b(stack_b);
	ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a == NULL || *stack_b == NULL)
		return ;
	if ((*stack_a)->next == NULL || (*stack_b)->next == NULL)
		return ;
	rotate_a(stack_a);
	rotate_b(stack_b);
	ft_printf("rr\n");
}
