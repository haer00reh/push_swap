/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorsUtils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haer-reh <haer-reh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:31:33 by haer-reh          #+#    #+#             */
/*   Updated: 2025/12/18 20:08:03 by haer-reh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	IsSorted(t_list *list)
{
	while (list && list->next)
	{
		if (list->content > list->next->content)
			return (0);
		list = list->next;
	}
	return (1);
}
void	ExitError(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
int	HasDup(t_list *list)
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

int	OutOfRange(t_list *list)
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
	if (OutOfRange(a->top))
		ExitError();
	if (IsSorted(a->top))
		return(1);
	if (HasDup(a->top))
		ExitError();
	return (0);
}
