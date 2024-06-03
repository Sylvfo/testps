/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:29:39 by sforster          #+#    #+#             */
/*   Updated: 2024/06/03 14:14:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	stack_a = NULL;
	if (checks(argc, argv) == 1)
		return (0);
	if (get_numbers(argc, argv, &stack_a) == 1)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (is_a_sorted(stack_a) == 1)
		return (0);
	if (small_stack(&stack_a) == 1)
		return (0);
	sorting(&stack_a, &stack_b);
	ft_free_list(stack_a);
	ft_free_list(stack_b);
	return (0);
}

void	sorting(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	len = stack_len(*stack_a);
	if (len < 7)
		sort_four_six(stack_a, stack_b, len);
	else
	{
		push_b(stack_a, stack_b);
		push_b(stack_a, stack_b);
		sort_two_b(stack_b);
		len++;
		while ((len) > 3)
		{
			re_index_ab(stack_a, stack_b);
			target_nodes(stack_a, stack_b);
			cost_analyse_main(stack_a, stack_b);
			partition(stack_a, stack_b);
			len = stack_len(*stack_a);
		}
	}
	re_index_ab(stack_a, stack_b);
	sort_three(stack_a);
	top_b(stack_b);
	stack_b_to_stack_a(stack_a, stack_b);
}

void	partition(t_stack **stack_a, t_stack **stack_b)
{
	find_cheapest(stack_a);
	write_notes(stack_a, stack_len(*stack_a), stack_len(*stack_b));
	play_notes(stack_a, stack_b);
	push_b(stack_a, stack_b);
}
