/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:39:27 by sforster          #+#    #+#             */
/*   Updated: 2024/06/03 13:33:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// type 1
void	rot_a_rot_b_part(t_stack *node_a)
{
	int	rotations_a;
	int	rotations_b;

	rotations_a = node_a->index;
	rotations_b = node_a->target_node->index;
	if (rotations_a > rotations_b)
	{
		node_a->partition->ra = rotations_a - rotations_b;
		node_a->partition->rr = rotations_b;
		return ;
	}
	else if (rotations_a == rotations_b)
	{
		node_a->partition->rr = rotations_b;
		return ;
	}
	else
	{
		node_a->partition->rb = rotations_b - rotations_a;
		node_a->partition->rr = rotations_a;
	}
	return ;
}

// type 2
void	rot_a_rev_b_part(t_stack *node_a, int len_b)
{
	int	rotations_a;
	int	rotations_b;

	rotations_a = node_a->index;
	rotations_b = len_b - node_a->target_node->index;
	if (node_a->target_node->index == 0)
		rotations_b = 0;
	node_a->partition->ra = rotations_a;
	node_a->partition->rrb = rotations_b;
	return ;
}

// type 3
void	rev_a_rot_b_part_part(t_stack *node_a, int len_a)
{
	int	rotations_a;
	int	rotations_b;

	rotations_a = len_a - node_a->index;
	if (node_a->index == 0)
		rotations_a = 0;
	rotations_b = node_a->target_node->index;
	node_a->partition->rra = rotations_a;
	node_a->partition->rb = rotations_b;
	return ;
}

// type 4
void	rev_a_rev_b_part(t_stack *node_a, int len_a, int len_b)
{
	int	rotations_a;
	int	rotations_b;

	if (node_a->index == 0 && node_a->target_node->index != 0)
	{
		rotations_a = 0;
		rotations_b = len_b - node_a->target_node->index;
		node_a->partition->rra = 0;
		node_a->partition->rrb = rotations_b;
		return ;
	}
	else if (node_a->index != 0 && node_a->target_node->index == 0)
	{
		rotations_b = 0;
		rotations_a = len_a - node_a->index;
		node_a->partition->rra = rotations_a;
		node_a->partition->rrb = 0;
		return ;
	}
	else if (node_a->index != 0 && node_a->target_node->index != 0)
		rev_a_rev_b_part_2(node_a, len_a, len_b);
	return ;
}

// type 4 suite
void	rev_a_rev_b_part_2(t_stack *node_a, int len_a, int len_b)
{
	int	rotations_a;
	int	rotations_b;

	rotations_a = len_a - node_a->index;
	rotations_b = len_b - node_a->target_node->index;
	if (rotations_a > rotations_b)
	{
		node_a->partition->rra = rotations_a - rotations_b;
		node_a->partition->rrr = rotations_b;
		return ;
	}
	else if (rotations_a == rotations_b)
	{
		node_a->partition->rrr = rotations_a;
		return ;
	}
	else if (rotations_b > rotations_a)
	{
		node_a->partition->rrb = rotations_b - rotations_a;
		node_a->partition->rrr = rotations_a;
		return ;
	}
	return ;
}
