/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haer-reh <haer-reh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 10:03:41 by haer-reh          #+#    #+#             */
/*   Updated: 2025/12/26 13:24:45 by haer-reh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static int	count_lis(t_stack *a)
{
	int		i;
	t_list	*tmp;
	
	i = 0;
	tmp = a->top;
	while (tmp)
	{
		if (tmp->in_lis)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

static void	rotate_to_smallest(t_stack *a, int lis_len)
{
	int		pos;
	t_list	*tmp;

	pos = 0;
	tmp = a->top;
	while (tmp)
	{
		if (tmp->index == 0)
			break;
		pos++;
		tmp = tmp->next;
	}
	if (pos <= lis_len / 2)
	{
		while (pos > 0)
		{
			ra(a);
			pos--;
		}
	}
	else
	{
		while (pos < lis_len)
		{
			rra(a);
			pos++;
		}
	}
}

void	apply_algorithms(t_stack *a, t_stack *b)
{
	int	(lis_len), (rotations), (tp);

	lis_len = count_lis(a);
	tp = a->size - lis_len;
	rotations = 0;
	while (tp > 0)
	{
		if (!a->top->in_lis)
		{
			pb(a, b);
			tp--;
			rotations = 0;
		}
		else
		{
			ra(a);
			rotations++;
			if (rotations >= lis_len)
				break;
		}
	}
	rotate_to_smallest(a, lis_len);
}
