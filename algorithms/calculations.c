/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haer-reh <haer-reh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:22:58 by haer-reh          #+#    #+#             */
/*   Updated: 2025/12/30 12:48:46 by haer-reh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	calculate_cost(int pos_b, int pos_a, int size_b, int size_a)
{
	int	cost_a;
	int	cost_b;

	if (pos_b <= size_b / 2)
		cost_b = pos_b;
	else
		cost_b = size_b - pos_b;
	if (pos_a <= size_a / 2)
		cost_a = pos_a;
	else
		cost_a = size_a - pos_a;
	return (cost_a + cost_b + 1);
}

void	find_cheapest_move(t_stack *b, t_stack *a, int *best_pos)
{
	t_list	*tmp;
	int		pos_b;
	int		min_cost;
	int		cost;
	int		target_pos;

	tmp = b->top;
	pos_b = 0;
	min_cost = __INT_MAX__;
	*best_pos = 0;
	while (tmp)
	{
		target_pos = find_target_pos(a, tmp->index);
		cost = calculate_cost(pos_b, target_pos, b->size, a->size);
		if (cost < min_cost)
		{
			min_cost = cost;
			*best_pos = pos_b;
		}
		tmp = tmp->next;
		pos_b++;
	}
}

int	find_min_pos_in_stack(t_stack *a)
{
	t_list	*check;
	int		pos;
	int		min_index;
	int		min_pos;

	check = a->top;
	pos = 0;
	min_index = __INT_MAX__;
	min_pos = 0;
	while (check)
	{
		if (check->index < min_index)
		{
			min_index = check->index;
			min_pos = pos;
		}
		check = check->next;
		pos++;
	}
	return (min_pos);
}
