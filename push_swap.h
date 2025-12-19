/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haer-reh <haer-reh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:46:13 by haer-reh          #+#    #+#             */
/*   Updated: 2025/12/19 18:47:44 by haer-reh         ###   ########.fr       */
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

char	**ft_split(char *str, char sep);
void	free_split(char **split);
int		count_words(char *str, char sep);
long	ft_atol(char *str);
char	*copy_word(char *str, int len);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(int content);
void	ft_lstclear(t_list **lst);
int	check(t_stack *a);
void	ExitError(void);
void	sa(t_stack *a);
void	ra(t_stack *a);
void	rra(t_stack *a);


#endif