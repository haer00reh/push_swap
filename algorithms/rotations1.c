/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haer-reh <haer-reh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 18:47:22 by haer-reh          #+#    #+#             */
/*   Updated: 2025/12/30 12:48:31 by haer-reh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_to_smallest(t_stack *a)
{
	int		pos;
	int		min_index;
	t_list	*tmp;

	pos = 0;
	min_index = __INT_MAX__;
	tmp = a->top;
	while (tmp)
	{
		if (tmp->index < min_index)
		{
			min_index = tmp->index;
			break ;
		}
		pos++;
		tmp = tmp->next;
	}
	rotate_to_position(a, pos);
}

void	final_rotate_a(t_stack *a)
{
	int	min_pos;

	min_pos = find_min_pos_in_stack(a);
	if (min_pos <= a->size / 2)
		while (min_pos-- > 0)
			ra(a);
	else
	{
		min_pos = a->size - min_pos;
		while (min_pos-- > 0)
			rra(a);
	}
}

void	move_to_top_b(t_stack *b, int best_pos)
{
	if (best_pos <= b->size / 2)
		while (best_pos-- > 0)
			rb(b);
	else
		while (best_pos++ < b->size)
			rrb(b);
}
