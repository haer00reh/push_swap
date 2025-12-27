/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haer-reh <haer-reh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 10:03:41 by haer-reh          #+#    #+#             */
/*   Updated: 2025/12/27 17:16:06 by haer-reh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_cost(int pos_b, int pos_a, int size_b, int size_a)
{
	int	cost_a;
	int	cost_b;
	int	cost;

	if (pos_b <= size_b / 2)
		cost_b = pos_b;
	else
		cost_b = size_b - pos_b;
	if (pos_a <= size_a / 2)
		cost_a = pos_a;
	else
		cost_a = size_a - pos_a;
	if ((pos_b <= size_b / 2 && pos_a <= size_a / 2)
		|| (pos_b > size_b / 2 && pos_a > size_a / 2))
	{
		if (cost_b > cost_a)
			cost = cost_b;
		else
			cost = cost_a;
	}
	else
		cost = cost_b + cost_a;
	return (cost + 1);
}

static void	find_cheapest_move(t_stack *b, t_stack *a, int *best_pos)
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

static void	combined_rotations(t_stack *a, t_stack *b, int *pos_b,
							int *target_pos)
{
	int	rotate_b_forward;
	int	rotate_a_forward;

	rotate_b_forward = (*pos_b <= b->size / 2);
	rotate_a_forward = (*target_pos <= a->size / 2);
	if (rotate_b_forward && rotate_a_forward)
	{
		while (*pos_b > 0 && *target_pos > 0)
		{
			rr(a, b);
			(*pos_b)--;
			(*target_pos)--;
		}
	}
	else if (!rotate_b_forward && !rotate_a_forward)
	{
		while (*pos_b < b->size && *target_pos < a->size)
		{
			rrr(a, b);
			(*pos_b)++;
			(*target_pos)++;
		}
	}
}

static void	finish_rotations(t_stack *a, t_stack *b, int pos_b,
							int target_pos)
{
	int	rotate_b_forward;
	int	rotate_a_forward;

	rotate_b_forward = (pos_b <= b->size / 2);
	rotate_a_forward = (target_pos <= a->size / 2);
	if (rotate_b_forward)
		while (pos_b-- > 0)
			rb(b);
	else
		while (pos_b++ < b->size)
			rrb(b);
	if (rotate_a_forward)
		while (target_pos-- > 0)
			ra(a);
	else
		while (target_pos++ < a->size)
			rra(a);
}

static void	execute_move(t_stack *a, t_stack *b, int pos_b, int target_pos)
{
	combined_rotations(a, b, &pos_b, &target_pos);
	finish_rotations(a, b, pos_b, target_pos);
	pa(a, b);
}

static void	move_to_top_b(t_stack *b, int best_pos)
{
	if (best_pos <= b->size / 2)
		while (best_pos-- > 0)
			rb(b);
	else
		while (best_pos++ < b->size)
			rrb(b);
}

static int	find_min_pos_in_stack(t_stack *a)
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

static void	final_rotate_a(t_stack *a)
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

static void	push_cheapest_element(t_stack *a, t_stack *b)
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

static int	find_smallest_pos(t_stack *a)
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

static int	find_min_position(t_stack *a)
{
	int		pos;
	t_list	*tmp;

	pos = 0;
	tmp = a->top;
	while (tmp)
	{
		if (tmp->index < __INT_MAX__)
			break ;
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

static void	rotate_to_position(t_stack *a, int pos)
{
	if (pos <= a->size / 2)
		while (pos-- > 0)
			ra(a);
	else
		while (pos++ < a->size)
			rra(a);
}

static void	rotate_to_smallest(t_stack *a, int lis_len)
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

static void	push_with_sort(t_stack *a, t_stack *b, int median)
{
	int	elem_index;

	elem_index = a->top->index;
	pb(a, b);
	if (b->size > 1 && elem_index < median / 2)
		rb(b);
}

static void	push_non_lis(t_stack *a, t_stack *b, int tp, int median)
{
	int	lis_len;
	int	rotations;

	lis_len = count_lis(a);
	rotations = 0;
	while (tp > 0)
	{
		if (!a->top->in_lis)
		{
			if (tp > 5)
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

void	apply_algorithms(t_stack *a, t_stack *b)
{
	int	lis_len;
	int	tp;
	int	median;

	lis_len = count_lis(a);
	tp = a->size - lis_len;
	median = a->size / 2;
	push_non_lis(a, b, tp, median);
	push_back_to_a(a, b);
	rotate_to_smallest(a, a->size);
}
