/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:03:57 by sforster          #+#    #+#             */
/*   Updated: 2024/05/30 13:53:26 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "librairies/printf/ft_printf.h"
# include "librairies/libft/libft.h"

typedef struct notes
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_notes;

typedef struct s_stack
{
	long long int	num;
	int				index;
	int				push_cost;
	int				above_median;
	int				cheapest;
	int				type;
	struct notes	*partition;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// main
void		sorting(t_stack **stack_a, t_stack **stack_b);
void		partition(t_stack **stack_a, t_stack **stack_b);

// write partition
void		find_cheapest(t_stack **stack_a);
void		write_notes(t_stack **stack_a, int len_a, int len_b);
void		init_partition(t_stack *node_a);

// play partition
void		play_notes(t_stack **stack_a, t_stack **stack_b);
void		play_rarbrr(t_stack *node, t_stack **stack_a, t_stack **stack_b);
void		play_rrarrbrrr(t_stack *node, t_stack **stack_a, t_stack **stack_b);

//stack b to a 
void		stack_b_to_stack_a(t_stack **stack_a, t_stack **stack_b);
void		back_a_smaller(t_stack **stack_a, t_stack **stack_b);
void		top_b(t_stack **stack_b);

// target
void		target_nodes(t_stack **stack_a, t_stack **stack_b);
void		above_med(t_stack **stack_b, t_stack *maxb);
void		target_max(t_stack *cur_a, t_stack *cur_b, t_stack *maxb);
void		target_up_median(t_stack *cur_a, t_stack *cur_b);
void		target_to_median(t_stack *cur_a, t_stack *cur_b, t_stack **stack_b);

// cost analysis
void		cost_analyse_main(t_stack **stack_a, t_stack **stack_b);
void		cost(t_stack *node_a, int len_a, int len_b);
void		cost_a(t_stack *node_a, int len_a, int len_b);
void		cost_b(t_stack *node_a, int len_a, int len_b);

////////////////////////////////////////

// len four six
void		sort_four_six(t_stack **stack_a, t_stack **stack_b, int len);
void		sort_three_b(t_stack **head);
void		sort_two_b(t_stack **stack_b);

// len two three
int			small_stack(t_stack **head);
void		sort_two(t_stack **head);
void		sort_three(t_stack **head);

// check
int			ft_isdigit(int c);
int			checks(int argc, char **argv);
int			two_arg(int argc);
int			check_empty_arg(char **argv);
int			check_digit(char **argv);

// get numbers
int			get_numbers(int argc, char **argv, t_stack **stack_a);
int			get_number_line(t_stack **stack_a, char *argv);
int			get_number_mult(t_stack **stack_a, char **argv);
int			check_double(t_stack **stack_a, t_stack *newnum);

//chained list
t_stack		*ft_lstnewnum(int content, int i);
void		ft_lstadd_backnum(t_stack **lst, t_stack *new);
void		ft_free_tab(char **tab);
void		ft_free_list(t_stack *head);

////////////////////////////////////////

// utils plus
void		re_index(t_stack **stack_a);
void		re_index_ab(t_stack **stack_a, t_stack **stack_b);
int			check_min_max2(t_stack *numb, char *argv, t_stack **stack_a);
int			check_min_max(t_stack *numb, char **spl, t_stack **stack_a, int i);
void		free_min_max(t_stack *numb, char **spl, t_stack **stack_a);

// prints
void		print_lists(t_stack *a, t_stack *b);
void		print_list(t_stack *head);

// utils
t_stack		*min_node(t_stack **head);
t_stack		*max_node(t_stack **head);
int			is_a_sorted(t_stack *stack_a);
int			stack_len(t_stack *stack_a);
void		zero_zero(char *str);

////////////////////////////////////////

// count_rotations 
int			rot_a_rot_b(t_stack *node_a);
int			rot_a_rev_b(t_stack *node_a, int len_b);
int			rev_a_rot_b(t_stack *node_a, int len_a);
int			rev_a_rev_b(t_stack *node_a, int len_a, int len_b);

// notes
void		rot_a_rot_b_part(t_stack *node_a);
void		rot_a_rev_b_part(t_stack *node_a, int len_a);
void		rev_a_rot_b_part_part(t_stack *node_a, int len_a);
void		rev_a_rev_b_part(t_stack *node_a, int len_a, int len_b);
void		rev_a_rev_b_part_2(t_stack *node_a, int len_a, int len_b);

////////////////////////////////////////
// swap
void		swap(t_stack **stack);
void		sa(t_stack **stack_a);
void		sb(t_stack **stack_b);
void		ss(t_stack **stack_a, t_stack **stack_b);

//rotate
void		rotate_a(t_stack **stack_a);
void		ra(t_stack **stack_a);
void		rotate_b(t_stack **stack_b);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);

// rev rotate
void		rev_rotate(t_stack **stack);
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);

// push
void		push_a(t_stack **s_a, t_stack **s_b);
void		push_b(t_stack **s_a, t_stack **s_b);

#endif