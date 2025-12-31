/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haer-reh <haer-reh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 18:41:54 by haer-reh          #+#    #+#             */
/*   Updated: 2025/12/30 12:48:26 by haer-reh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_both_forward(t_stack *a, t_stack *b, int *pos_b,
						int *target_pos)
{
	while (*pos_b > 0 && *target_pos > 0)
	{
		rr(a, b);
		(*pos_b)--;
		(*target_pos)--;
	}
}

void	rotate_both_backward(t_stack *a, t_stack *b, int *pos_b,
						int *target_pos)
{
	while (*pos_b < b->size && *target_pos < a->size)
	{
		rrr(a, b);
		(*pos_b)++;
		(*target_pos)++;
	}
}

void	rotate_single_b(t_stack *b, int pos_b, int forward)
{
	if (forward)
		while (pos_b-- > 0)
			rb(b);
	else
		while (pos_b++ < b->size)
			rrb(b);
}

void	rotate_single_a(t_stack *a, int target_pos, int forward)
{
	if (forward)
		while (target_pos-- > 0)
			ra(a);
	else
		while (target_pos++ < a->size)
			rra(a);
}

void	rotate_to_position(t_stack *a, int pos)
{
	if (pos <= a->size / 2)
		while (pos-- > 0)
			ra(a);
	else
		while (pos++ < a->size)
			rra(a);
}
