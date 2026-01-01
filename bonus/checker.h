/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haer-reh <haer-reh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 14:20:02 by haer-reh          #+#    #+#             */
/*   Updated: 2025/12/31 17:54:00 by haer-reh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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

void	ft_lstclear(t_list **lst);
void	c_rrr(t_stack *a, t_stack *b);
void	c_rr(t_stack *a, t_stack *b);
void	c_rrb(t_stack *b);
void	c_rra(t_stack *a);
void	c_rb(t_stack *b);
void	c_ra(t_stack *a);
void	c_pa(t_stack *a, t_stack *b);
void	c_pb(t_stack *a, t_stack *b);
void	c_ss(t_stack *a, t_stack *b);
void	c_sb(t_stack *b);
void	c_sa(t_stack *a);
int		is_sorted(t_list *list);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(const char *s);
char	*extract_n(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
void	begin_init(int ac, char **av, t_stack *a, t_stack *b);

#endif