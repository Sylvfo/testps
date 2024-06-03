/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_rotations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:22:52 by sforster          #+#    #+#             */
/*   Updated: 2024/05/30 13:34:33 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rot_a_rot_b(t_stack *node_a)
{
	int	rotations_a;
	int	rotations_b;

	rotations_a = node_a->index;
	rotations_b = node_a->target_node->index;
	if (rotations_a > rotations_b)
		return (rotations_a);
	return (rotations_b);
}

int	rot_a_rev_b(t_stack *node_a, int len_b)
{
	int	rotations_a;
	int	rotations_b;

	rotations_a = node_a->index;
	rotations_b = len_b - node_a->target_node->index;
	if (node_a->target_node->index == 0)
		rotations_b = 0;
	return (rotations_a + rotations_b);
}

int	rev_a_rot_b(t_stack *node_a, int len_a)
{
	int	rotations_a;
	int	rotations_b;

	rotations_a = len_a - node_a->index;
	if (node_a->index == 0)
		rotations_a = 0;
	rotations_b = node_a->target_node->index;
	return (rotations_a + rotations_b);
}

int	rev_a_rev_b(t_stack *node_a, int len_a, int len_b)
{
	int	rotations_a;
	int	rotations_b;

	rotations_a = len_a - node_a->index;
	if (node_a->index == 0)
		rotations_a = 0;
	rotations_b = len_b - node_a->target_node->index;
	if (node_a->target_node->index == 0)
		rotations_b = 0;
	if (rotations_a > rotations_b)
		return (rotations_a);
	return (rotations_b);
}
