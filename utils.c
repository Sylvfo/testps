/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:54:06 by sforster          #+#    #+#             */
/*   Updated: 2024/05/30 12:54:45 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*min_node(t_stack **head)
{
	t_stack		*min;
	t_stack		*current;

	current = *head;
	min = malloc(sizeof(t_stack));
	if (!min)
		return (NULL);
	min->num = 2147483648;
	while (current != NULL)
	{
		if (current->num < min->num)
		{
			min->index = current->index;
			min->num = current->num;
		}
		current = current->next;
	}
	return (min);
}

t_stack	*max_node(t_stack **head)
{
	t_stack		*max;
	t_stack		*current;

	current = *head;
	max = malloc(sizeof(t_stack));
	if (!max)
		return (NULL);
	max->num = -2147483649;
	while (current != NULL)
	{
		if (current->num > max->num)
		{
			max->index = current->index;
			max->num = current->num;
		}
		current = current->next;
	}
	return (max);
}

int	is_a_sorted(t_stack *stack_a)
{
	t_stack		*current;

	current = stack_a;
	while (current->next != NULL)
	{
		if (current->num < current->next->num)
			current = current->next;
		else
			return (0);
	}
	ft_free_list(stack_a);
	return (1);
}

int	stack_len(t_stack *stack_a)
{
	t_stack		*current;
	int			i;

	i = 0;
	current = stack_a;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
}

void	zero_zero(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] == '0')
		i++;
	if (i == 0)
		return ;
	else if (str[i] == '\0')
	{
		str[0] = '0';
		str[1] = '\0';
		return ;
	}
	while (str[i])
	{
		str[j] = str[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return ;
}
