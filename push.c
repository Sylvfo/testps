/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:41:41 by sforster          #+#    #+#             */
/*   Updated: 2024/05/30 13:42:06 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pb (push b) : Prend le premier élément au sommet de a et le met sur b.
void	push_b(t_stack **s_a, t_stack **s_b)
{
	t_stack	*head;

	if (*s_a == NULL)
		return ;
	head = *s_a;
	*s_a = (*s_a)->next;
	if (*s_a != NULL)
		(*s_a)->prev = NULL;
	head->next = *s_b;
	if (*s_b != NULL)
		(*s_b)->prev = head;
	*s_b = head;
	ft_printf("pb\n");
}

// pa (push a) : Prend le premier élément au sommet de b et le met sur a.
void	push_a(t_stack **s_a, t_stack **s_b)
{
	t_stack	*head;

	if (*s_b == NULL)
		return ;
	head = *s_b;
	*s_b = (*s_b)->next;
	if (*s_b != NULL)
		(*s_b)->prev = NULL;
	head->next = *s_a;
	if (*s_a != NULL)
		(*s_a)->prev = head;
	*s_a = head;
	ft_printf("pa\n");
}
