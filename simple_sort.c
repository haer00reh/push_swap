/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haer-reh <haer-reh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 19:43:45 by haer-reh          #+#    #+#             */
/*   Updated: 2025/12/30 20:28:11 by haer-reh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
}


void	sort_two(t_stack *a)
{
	if (a->top->content > a->top->next->content)
		ra(a);
}

void	sort_three(t_stack *a)
{
	int (one), (two), (three);
	one = a->top->content;
	two = a->top->next->content;
	three = a->top->next->next->content;
	if (one > two && two < three && one < three)
		sa(a);
	else if (one > two && two > three && one > three)
	{
		sa(a);
		rra(a);
	}
	else if (one < two && one < three && two > three)
	{
		rra(a);
		sa(a);
	}
	else if (one > two && two < three && one > three)
	{
		ra(a);
	}
	else if (one < two && one > three && two > three)
	{
		rra(a);
		sa(a);
	}
}

void sort_five(t_stack *a, t_stack *b)
{
    while (a->size > 3)
    {
		int pos = find_min_pos_in_stack(a);
		if (pos <= a->size / 2)
			while (pos-- > 0)
				ra(a);
		else
			while (pos++ < a->size)
				rra(a);
		pb(a, b);
    }
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}

void sort_four(t_stack *a, t_stack *b)
{
    while (a->size > 2)
    {
		int pos = find_min_pos_in_stack(a);
		if (pos <= a->size / 2)
			while (pos-- > 0)
				ra(a);
		else
			while (pos++ < a->size)
				rra(a);
		pb(a, b);
    }
	sort_two(a);
	while (b->size > 0)
		pa(a, b);
}
