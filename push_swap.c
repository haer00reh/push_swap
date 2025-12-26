/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haer-reh <haer-reh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:45:52 by haer-reh          #+#    #+#             */
/*   Updated: 2025/12/26 13:22:57 by haer-reh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_input(int ac, char **av, t_list **list)
{
	char	**s;
	int 	(i), (j);
	
	i = 1;
	*list = NULL;
		while (i < ac)
		{
		s = ft_split(av[i], ' ');
		j = 0;
		while (s[j])
		{
			ft_lstadd_back(list, ft_lstnew(ft_atol(s[j])));
			j++;
		}
		i++;
		free_split(s);
		free(s);
		}
}

void	print_stack(t_stack *a)
{
	t_list *tmp = a->top;
	while (tmp)
	{
		printf("content: %d in_lis: %d\n", tmp->content, tmp->in_lis);
		tmp = tmp->next;
	}
}

int main(int ac, char **av)
{
	t_list	*list;
	t_stack	a;
	t_stack	b;

	list = NULL;
	if (ac < 2)
		return (-1);
	if (ac >= 2)
	{
	parse_input(ac, av, &list);
	a.top = list;
	a.size = ft_lstsize(list);
	t_index(&a);
		if (check(&a))
		{
			ft_lstclear(&a.top);
			ExitError();
		}
	b.top = NULL;
	b.size = 0;
	find_lis(&a);
	apply_algorithms(&a, &b);
	print_stack(&a);
	}
	ft_lstclear(&a.top);
	ft_lstclear(&b.top);
	return (0);
}
