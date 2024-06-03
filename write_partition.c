/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_partition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:28:22 by sforster          #+#    #+#             */
/*   Updated: 2024/05/30 13:48:02 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_cheapest(t_stack **stack_a)
{
	t_stack		*current;
	t_stack		*cheapest_node;
	int			min_cost;

	current = *stack_a;
	cheapest_node = NULL;
	min_cost = 2147483647;
	while (current != NULL)
	{
		if (current->push_cost < min_cost)
		{
			min_cost = current->push_cost;
			cheapest_node = current;
		}
		current = current->next;
	}
	if (cheapest_node != NULL)
	{
		cheapest_node->cheapest = 2;
	}
}

void	write_notes(t_stack **stack_a, int len_a, int len_b)
{
	t_stack		*node_a;
	int			type;

	node_a = *stack_a;
	while (node_a->cheapest != 2 && node_a != NULL)
		node_a = node_a->next;
	init_partition(node_a);
	type = node_a->type;
	if (type == 0)
		return ;
	if (type == 1)
		rot_a_rot_b_part(node_a);
	if (type == 2)
		rot_a_rev_b_part(node_a, len_b);
	if (type == 3)
		rev_a_rot_b_part_part(node_a, len_a);
	if (type == 4)
		rev_a_rev_b_part(node_a, len_a, len_b);
	return ;
}

void	init_partition(t_stack *node_a)
{
	node_a->partition = malloc(sizeof(t_notes));
	if (!node_a->partition)
		return ;
	node_a->partition->ra = 0;
	node_a->partition->rb = 0;
	node_a->partition->rr = 0;
	node_a->partition->rra = 0;
	node_a->partition->rrb = 0;
	node_a->partition->rrr = 0;
	return ;
}
