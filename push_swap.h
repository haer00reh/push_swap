/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haer-reh <haer-reh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:46:13 by haer-reh          #+#    #+#             */
/*   Updated: 2025/12/31 14:21:57 by haer-reh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				index;
	int				in_lis;
	struct s_list	*next;
}					t_list;

typedef struct s_stack
{
	t_list	*top;
	int		size;
}	t_stack;

void	find_lis(t_stack *a);
char	**ft_split(char *str, char sep);
void	free_split(char **split);
int		count_words(char *str, char sep);
long	ft_atol(char *str);
char	*copy_word(char *str, int len);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(int content);
void	ft_lstclear(t_list **lst);
int		check(t_stack *a);
void	exit_error(void);
void	sa(t_stack *a);
void	ra(t_stack *a);
void	rra(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rrb(t_stack *b);
void	rb(t_stack *b);
int		is_sorted(t_list *list);
int		has_dup(t_list *list);
int		outof_range(t_list *list);
int		check(t_stack *a);
void	parse_input(int ac, char **av, t_list **list);
void	print_stack(t_stack *a);
void	t_index(t_stack *a);
void	assign_index(t_stack *a, int *arr);
void	isort(int *arr, int len);
void	find_lis(t_stack *a);
void	apply_algorithms(t_stack *a, t_stack *b);
int		find_target_pos(t_stack *a, int b_index);
void	sort_three(t_stack *a);
void	rotate_both_forward(t_stack *a, t_stack *b, int *pos_b,
			int *target_pos);
void	rotate_both_backward(t_stack *a, t_stack *b, int *pos_b,
			int *target_pos);
void	rotate_single_b(t_stack *b, int pos_b, int forward);
void	rotate_single_a(t_stack *a, int target_pos, int forward);
void	push_cheapest_element(t_stack *a, t_stack *b);
void	push_back_to_a(t_stack *a, t_stack *b);
void	push_non_lis(t_stack *a, t_stack *b, int tp, int median);
int		find_min_pos_in_stack(t_stack *a);
void	execute_move(t_stack *a, t_stack *b, int pos_b, int target_pos);
int		find_smallest_pos(t_stack *a);
int		count_lis(t_stack *a);
int		calculate_cost(int pos_b, int pos_a, int size_b, int size_a);
void	find_cheapest_move(t_stack *b, t_stack *a, int *best_pos);
void	rotate_to_smallest(t_stack *a);
void	final_rotate_a(t_stack *a);
void	move_to_top_b(t_stack *b, int best_pos);
void	push_with_sort(t_stack *a, t_stack *b, int median);
void	compute_lis(int *arr, int size, int *prev, int *lis);
int		find_lis_end(int *lis, int size);
void	mark_lis(t_stack *a, int *arr, int *prev, int pos);
void	sort_two(t_stack *a);
void	rotate_to_position(t_stack *a, int pos);
void	sort_five(t_stack *a, t_stack *b);
void	simple_sort(t_stack *a, t_stack *b);
void 	sort_four(t_stack *a, t_stack *b);
void	begin_init(int ac, char **av, t_stack *a, t_stack *b);

#endif