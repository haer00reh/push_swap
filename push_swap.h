/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haer-reh <haer-reh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:46:13 by haer-reh          #+#    #+#             */
/*   Updated: 2025/12/26 11:02:39 by haer-reh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
void	ExitError(void);
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
int		IsSorted(t_list *list);
int		HasDup(t_list *list);
int		OutOfRange(t_list *list);
int		check(t_stack *a);
void	parse_input(int ac, char **av, t_list **list);
void	print_stack(t_stack *a);
void	t_index(t_stack *a);
void	assign_index(t_stack *a, int *arr);
void	isort(int *arr, int len);
void	find_lis(t_stack *a);
void	apply_algorithms(t_stack *a, t_stack *b);


#endif