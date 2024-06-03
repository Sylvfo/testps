/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_analysis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:33:23 by sforster          #+#    #+#             */
/*   Updated: 2024/05/30 13:34:29 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_analyse_main(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*current;

	current = *stack_a;
	while (current != NULL)
	{
		cost(current, stack_len(*stack_a), stack_len(*stack_b));
		current = current->next;
	}
}

void	cost(t_stack *node_a, int len_a, int len_b)
{
	cost_a(node_a, len_a, len_b);
	cost_b(node_a, len_a, len_b);
}

void	cost_a(t_stack *node_a, int len_a, int len_b)
{
	int			rta_rtb;
	int			rta_rvb;
	int			rva_rtb;
	int			rva_rvb;

	rta_rtb = rot_a_rot_b(node_a);
	rta_rvb = rot_a_rev_b(node_a, len_b);
	rva_rtb = rev_a_rot_b(node_a, len_a);
	rva_rvb = rev_a_rev_b(node_a, len_a, len_b);
	if (rta_rtb + rta_rvb + rva_rtb + rva_rvb == 0)
		node_a->type = 5;
	else if (rta_rtb <= rta_rvb && rta_rtb <= rva_rtb && rta_rtb <= rva_rvb)
	{
		node_a->push_cost = rta_rtb;
		node_a->type = 1;
	}
	else if (rta_rvb < rta_rtb && rta_rvb <= rva_rtb && rta_rvb <= rva_rvb)
	{
		node_a->push_cost = rta_rvb;
		node_a->type = 2;
	}
	return ;
}

void	cost_b(t_stack *node_a, int len_a, int len_b)
{
	int			rta_rtb;
	int			rta_rvb;
	int			rva_rtb;
	int			rva_rvb;

	rta_rtb = rot_a_rot_b(node_a);
	rta_rvb = rot_a_rev_b(node_a, len_b);
	rva_rtb = rev_a_rot_b(node_a, len_a);
	rva_rvb = rev_a_rev_b(node_a, len_a, len_b);
	if (rva_rtb < rta_rtb && rva_rtb < rta_rvb && rva_rtb <= rva_rvb)
	{
		node_a->push_cost = rva_rtb;
		node_a->type = 3;
	}
	else if (rva_rvb < rta_rtb && rva_rvb < rta_rvb && rva_rvb < rva_rtb)
	{
		node_a->push_cost = rva_rvb;
		node_a->type = 4;
	}
	return ;
}
