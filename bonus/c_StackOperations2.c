/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackOperations2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haer-reh <haer-reh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 16:21:17 by haer-reh          #+#    #+#             */
/*   Updated: 2025/12/31 14:42:49 by haer-reh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	c_ra(t_stack *a)
{
	t_list	*first;
	t_list	*last;

	if (!a || a->size < 2)
		return ;
	first = a->top;
	a->top = first->next;
	first->next = NULL;
	last = a->top;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	c_rb(t_stack *b)
{
	t_list	*first;
	t_list	*last;

	if (!b || b->size < 2)
		return ;
	first = b->top;
	b->top = first->next;
	first->next = NULL;
	last = b->top;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	c_rra(t_stack *a)
{
	t_list	*last;
	t_list	*prev;

	if (!a || a->size < 2)
		return ;
	prev = NULL;
	last = a->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = a->top;
	a->top = last;
}

void	c_rrb(t_stack *b)
{
	t_list	*last;
	t_list	*prev;

	if (!b || b->size < 2)
		return ;
	prev = NULL;
	last = b->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = b->top;
	b->top = last;
}

void	c_rr(t_stack *a, t_stack *b)
{
	c_ra(a);
	c_rb(b);
}
