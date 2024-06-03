/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:45:22 by sforster          #+#    #+#             */
/*   Updated: 2024/05/30 13:47:10 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*head;

	head = *stack;
	if (!head)
	{
		return ;
	}
	if (head->next == NULL)
	{
		return ;
	}
	tmp = malloc(1 * sizeof(t_stack));
	if (!tmp)
	{
		return ;
	}
	tmp->num = head->num;
	head->num = head->next->num;
	head->next->num = tmp->num;
	free (tmp);
}

void	sa(t_stack **stack_a)
{
	if (*stack_a == NULL)
		return ;
	if ((*stack_a)->next == NULL)
		return ;
	swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_stack **stack_b)
{
	if (*stack_b == NULL)
		return ;
	if ((*stack_b)->next == NULL)
		return ;
	swap(stack_b);
	ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a == NULL || *stack_b == NULL)
		return ;
	if ((*stack_a)->next == NULL || (*stack_b)->next == NULL)
		return ;
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
