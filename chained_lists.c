/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_lists.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:02:49 by sforster          #+#    #+#             */
/*   Updated: 2024/06/03 14:17:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnewnum(int content, int i)
{
	t_stack	*result;

	result = malloc(sizeof(t_stack));
	if (!result)
		return (NULL);
	result->num = content;
	result->index = i;
	result->push_cost = 0;
	result->above_median = 0;
	result->cheapest = 1;
	result->partition = NULL;
	result->type = 0;
	result->next = NULL;
	result->prev = NULL;
	result->target_node = NULL;
	return (result);
}

void	ft_lstadd_backnum(t_stack **lst, t_stack *new)
{
	t_stack	*current;

	current = *lst;
	if (!lst)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (current->next != NULL)
	{
		current = current->next;
	}
	new->prev = current;
	current->next = new;
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_free_list(t_stack *head)
{
	t_stack	*current;
	t_stack	*tmp;

	current = head;
	while (current != NULL)
	{
		if (current->partition != NULL)
		{
			free (current->partition);
			current->partition = NULL;
		}
		tmp = current;
		current = current->next;
		free(tmp);
	}
	head = NULL;
}
