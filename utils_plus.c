/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_plus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:46:07 by sforster          #+#    #+#             */
/*   Updated: 2024/05/30 13:46:29 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	re_index(t_stack **stack)
{
	int			i;
	t_stack		*current;

	current = *stack;
	i = 0;
	while (current != NULL)
	{
		current->index = i;
		current->push_cost = 0;
		current->above_median = 0;
		current->cheapest = 1;
		current->type = 0;
		if (current->partition != NULL)
		{
			free (current->partition);
			current->partition = NULL;
		}
		i++;
		current = current->next;
	}
	return ;
}

void	re_index_ab(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a != NULL)
		re_index(stack_a);
	if (stack_b != NULL)
		re_index(stack_b);
	return ;
}

int	check_min_max(t_stack *numb, char **spl, t_stack **stack_a, int i)
{
	int	result;

	if (strlen(&spl[i][0]) > 11)
	{
		free_min_max(numb, spl, stack_a);
		return (1);
	}
	if (spl[i][0] == '0')
		return (0);
	result = ft_atoi(&spl[i][0]);
	if (spl[i][0] == '-' && result > 0)
	{
		free_min_max(numb, spl, stack_a);
		return (1);
	}
	else if (spl[i][0] != '-' && result < 0)
	{
		free_min_max(numb, spl, stack_a);
		return (1);
	}
	numb->num = result;
	return (0);
}

void	free_min_max(t_stack *numb, char **spl, t_stack **stack_a)
{
	free (numb);
	ft_free_list(*stack_a);
	ft_free_tab(spl);
}

int	check_min_max2(t_stack *numb, char *argv, t_stack **stack_a)
{
	int	result;

	if (strlen(argv) > 11)
	{
		free (numb);
		ft_free_list(*stack_a);
		return (1);
	}
	if (argv[0] == '0')
		return (0);
	result = ft_atoi(argv);
	if (argv[0] == '-' && result > 0)
	{
		free (numb);
		ft_free_list(*stack_a);
		return (1);
	}
	else if (argv[0] != '-' && result < 0)
	{
		free (numb);
		ft_free_list(*stack_a);
		return (1);
	}
	numb->num = result;
	return (0);
}
