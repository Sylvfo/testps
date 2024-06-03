/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:31:57 by sforster          #+#    #+#             */
/*   Updated: 2024/05/30 13:33:09 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checks(int argc, char **argv)
{
	if (two_arg(argc) == 1)
		return (1);
	if (check_empty_arg(argv) == 1)
		return (1);
	if (check_digit(argv) == 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}

int	two_arg(int argc)
{
	if (argc == 1)
	{
		return (1);
	}
	return (0);
}

int	check_empty_arg(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
	{
		if (ft_isdigit(argv[1][i]) == 1)
			return (0);
		i++;
	}
	ft_printf("Error\n");
	return (1);
}

int	check_digit(char **argv)
{
	int	i;
	int	x;

	x = 1;
	while (argv[x])
	{
		i = 0;
		while (argv[x][i])
		{
			if (argv[x][i] == ' ' )
				i++;
			else if (ft_isdigit(argv[x][i]) == 1)
				i++;
			else if (argv[x][i] == '-' && ft_isdigit(argv[x][i + 1]) == 1)
				i++;
			else if (argv[x][i] == '+' && ft_isdigit(argv[x][i + 1]) == 1)
				i++;
			else
				return (1);
		}
		x++;
	}
	return (0);
}
