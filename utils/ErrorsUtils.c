/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorsUtils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haer-reh <haer-reh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:31:33 by haer-reh          #+#    #+#             */
/*   Updated: 2025/12/30 13:58:14 by haer-reh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_list *list)
{
	while (list && list->next)
	{
		if (list->content > list->next->content)
			return (0);
		list = list->next;
	}
	return (1);
}

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	has_dup(t_list *list)
{
	t_list	*i;
	t_list	*j;

	i = list;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->content == j->content)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

int	outof_range(t_list *list)
{
	while (list)
	{
		if (list->content < -2147483648 || list->content > 2147483647)
			return (1);
		list = list->next;
	}
	return (0);
}

int	check(t_stack *a)
{
	if (!a || !a->top)
		return (1);
	if (outof_range(a->top))
		exit_error();
	if (is_sorted(a->top))
		exit(0);
	if (has_dup(a->top))
		exit_error();
	return (0);
}
