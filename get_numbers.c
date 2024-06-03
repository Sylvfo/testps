/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:34:53 by sforster          #+#    #+#             */
/*   Updated: 2024/05/30 13:35:27 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_numbers(int argc, char **argv, t_stack **stack_a)
{
	if (argc == 2)
		if (get_number_line(stack_a, argv[1]) == 1)
			return (1);
	if (argc > 2)
		if (get_number_mult(stack_a, argv) == 1)
			return (1);
	return (0);
}

int	get_number_line(t_stack **stack_a, char *argv)
{
	char		**spline;
	int			i;
	t_stack		*numb;

	i = 0;
	spline = ft_split(argv, ' ');
	while (spline[i])
	{
		zero_zero(spline[i]);
		numb = ft_lstnewnum(0, i);
		if (check_min_max(numb, spline, stack_a, i) == 1)
			return (1);
		if (check_double(stack_a, numb) == 1)
		{
			ft_free_tab(spline);
			return (1);
		}
		ft_lstadd_backnum(stack_a, numb);
		i++;
	}
	ft_free_tab(spline);
	return (0);
}

int	get_number_mult(t_stack **stack_a, char **argv)
{
	int			i;
	int			index;
	t_stack		*numb;

	if (!argv[2][0])
		return (1);
	i = 1;
	index = 0;
	while (argv[i])
	{
		zero_zero(argv[i]);
		numb = ft_lstnewnum(0, index);
		if (check_min_max2(numb, argv[i], stack_a) == 1)
			return (1);
		if (check_double(stack_a, numb) == 1)
			return (1);
		ft_lstadd_backnum(stack_a, numb);
		i++;
		index++;
	}
	return (0);
}

int	check_double(t_stack **stack_a, t_stack *newnum)
{
	t_stack		*current;

	current = *stack_a;
	while (current != NULL)
	{
		if (current->num == newnum->num)
		{
			free (newnum);
			ft_free_list(*stack_a);
			return (1);
		}
		current = current->next;
	}
	return (0);
}
