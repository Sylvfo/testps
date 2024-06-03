/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:40:58 by sforster          #+#    #+#             */
/*   Updated: 2024/05/30 13:41:21 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_stack *head)
{
	t_stack	*cur;

	if (head == NULL)
		return ;
	cur = head;
	while (cur != NULL)
	{
		ft_printf("num %i \n", cur->num);
		ft_printf("num %i, index %i \n", cur->num, cur->index);
		ft_printf("push_cost %i, above median %i, ",
			cur->push_cost, cur->above_median);
		ft_printf(" cheapest %i, type %i,", cur->cheapest, cur->type);
		if (cur->target_node != NULL)
			ft_printf("target %i \n", cur->target_node->num);
		if (cur->partition != NULL)
		{
			ft_printf("partition ra %i, rb %i, rr %i, ", cur->partition->ra,
				cur->partition->rb, cur->partition->rr);
			ft_printf("rra %i, rrb %i, rrr %i \n", cur->partition->rra,
				cur->partition->rrb, cur->partition->rrr);
		}
		cur = cur->next;
	}
}

void	print_lists(t_stack *a, t_stack *b)
{
	if (a != NULL)
	{
		ft_printf("\nstack_a: \n");
		print_list(a);
	}
	if (b != NULL)
	{
		ft_printf("\nstack_b: \n");
		print_list(b);
	}
	return ;
}
