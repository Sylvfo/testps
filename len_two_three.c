/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_two_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:36:44 by sforster          #+#    #+#             */
/*   Updated: 2024/05/30 13:38:11 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

int	small_stack(t_stack **head)
{
	if (stack_len(*head) == 1)
	{
		ft_free_list(*head);
		return (1);
	}
	if (stack_len(*head) == 2)
	{
		sort_two(head);
		ft_free_list(*head);
		return (1);
	}
	else if (stack_len(*head) == 3)
	{
		sort_three(head);
		ft_free_list(*head);
		return (1);
	}
	return (0);
}

void	sort_two(t_stack **head)
{
	if (stack_len(*head) != 2)
		return ;
	sa(head);
	return ;
}

void	sort_three(t_stack **head)
{
	t_stack	*min;
	t_stack	*max;

	min = min_node(head);
	max = max_node(head);
	if (min->index == 0 && max->index == 1)
	{
		rra(head);
		sa(head);
	}
	if (min->index == 1 && max->index == 2)
		sa(head);
	if (min->index == 2 && max->index == 1)
		rra(head);
	if (min->index == 1 && max->index == 0)
		ra(head);
	if (min->index == 2 && max->index == 0)
	{
		sa(head);
		rra(head);
	}
	free (min);
	free (max);
	return ;
}
