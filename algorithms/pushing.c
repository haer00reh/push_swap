/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haer-reh <haer-reh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 18:44:44 by haer-reh          #+#    #+#             */
/*   Updated: 2025/12/30 12:48:18 by haer-reh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_cheapest_element(t_stack *a, t_stack *b)
{
	int		best_pos;
	int		target_pos;
	int		i;
	t_list	*tmp;

	find_cheapest_move(b, a, &best_pos);
	tmp = b->top;
	i = 0;
	while (i < best_pos && tmp)
	{
		tmp = tmp->next;
		i++;
	}
	if (!tmp)
		return ;
	target_pos = find_target_pos(a, tmp->index);
	move_to_top_b(b, best_pos);
	execute_move(a, b, 0, target_pos);
}

void	push_back_to_a(t_stack *a, t_stack *b)
{
	int	target_pos;

	while (b->size > 0)
	{
		if (b->size <= 3)
		{
			target_pos = find_target_pos(a, b->top->index);
			execute_move(a, b, 0, target_pos);
		}
		else
			push_cheapest_element(a, b);
	}
	final_rotate_a(a);
}

void	push_with_sort(t_stack *a, t_stack *b, int median)
{
	int	elem_index;

	elem_index = a->top->index;
	pb(a, b);
	if (b->size > 1 && elem_index < median)
		rb(b);
}

void	push_non_lis(t_stack *a, t_stack *b, int tp, int median)
{
	int	lis_len;
	int	rotations;

	lis_len = count_lis(a);
	rotations = 0;
	while (tp > 0)
	{
		if (!a->top->in_lis)
		{
			if (tp > 2)
				push_with_sort(a, b, median);
			else
				pb(a, b);
			tp--;
			rotations = 0;
		}
		else
		{
			ra(a);
			rotations++;
			if (rotations >= lis_len)
				break ;
		}
	}
}
