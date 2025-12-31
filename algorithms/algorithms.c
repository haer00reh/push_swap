/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haer-reh <haer-reh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 10:03:41 by haer-reh          #+#    #+#             */
/*   Updated: 2025/12/30 12:48:53 by haer-reh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	execute_move(t_stack *a, t_stack *b, int pos_b, int target_pos)
{
	int	rotate_b_forward;
	int	rotate_a_forward;

	rotate_b_forward = (pos_b <= b->size / 2);
	rotate_a_forward = (target_pos <= a->size / 2);
	if (rotate_b_forward && rotate_a_forward)
		rotate_both_forward(a, b, &pos_b, &target_pos);
	else if (!rotate_b_forward && !rotate_a_forward)
		rotate_both_backward(a, b, &pos_b, &target_pos);
	rotate_single_b(b, pos_b, rotate_b_forward);
	rotate_single_a(a, target_pos, rotate_a_forward);
	pa(a, b);
}

int	find_smallest_pos(t_stack *a)
{
	t_list	*tmp;
	int		pos;
	int		min_index;
	int		min_pos;

	tmp = a->top;
	min_index = __INT_MAX__;
	pos = 0;
	min_pos = 0;
	while (tmp)
	{
		if (tmp->index < min_index)
		{
			min_index = tmp->index;
			min_pos = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	return (min_pos);
}

int	find_target_pos(t_stack *a, int b_index)
{
	t_list	*tmp;
	int		target_pos;
	int		min_diff;
	int		pos;
	int		diff;

	tmp = a->top;
	target_pos = -1;
	min_diff = __INT_MAX__;
	pos = 0;
	while (tmp)
	{
		diff = tmp->index - b_index;
		if (diff > 0 && diff < min_diff)
		{
			min_diff = diff;
			target_pos = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	if (target_pos == -1)
		return (find_smallest_pos(a));
	return (target_pos);
}

int	count_lis(t_stack *a)
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

void	apply_algorithms(t_stack *a, t_stack *b)
{
	int	lis_len;
	int	tp;
	int	median;

	lis_len = count_lis(a);
	tp = a->size - lis_len;
	median = (a->size * 3) / 7;
	push_non_lis(a, b, tp, median);
	push_back_to_a(a, b);
	rotate_to_smallest(a);
}
