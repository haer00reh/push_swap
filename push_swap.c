/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haer-reh <haer-reh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:45:52 by haer-reh          #+#    #+#             */
/*   Updated: 2025/12/18 14:09:27 by haer-reh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_input(int ac, char **av, t_list **list)
{
	char	**s;
	int 	(i), (j);
	
	i = 1;
	list = NULL;
		while (i < ac)
		{
		s = ft_split(av[i], ' ');
		j = 0;
		while (s[j])
		{
			ft_lstadd_back(&list, ft_lstnew(ft_atoi(s[j])));
			j++;
		}
		i++;
		}
	
}


int main(int ac, char **av)
{
	t_list	*list;
	t_stack	(a), (b);

	if (ac < 2)
		return (-1);
	if (ac >= 2)
	{
	parse_input(ac, av, &list);
	a.top = list;
	a.size = ft_lstsize(list);
	b.top = NULL;
	b.size = 0;
	}
	return (0);
}
