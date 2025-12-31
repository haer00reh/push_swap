/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackOperations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haer-reh <haer-reh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:01:32 by haer-reh          #+#    #+#             */
/*   Updated: 2025/12/31 14:42:40 by haer-reh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	c_sa(t_stack *a)
{
	t_list	*first;
	t_list	*second;

	if (!a || a->size < 2)
		return ;
	first = a->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	a->top = second;
}

void	c_sb(t_stack *b)
{
	t_list	*first;
	t_list	*second;

	if (!b || b->size < 2)
		return ;
	first = b->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	b->top = second;
}

void	c_ss(t_stack *a, t_stack *b)
{
	c_sa(a);
	c_sb(b);
}

void	c_pa(t_stack *a, t_stack *b)
{
	t_list	*tmp;

	if (!b || b->size == 0)
		return ;
	tmp = b->top;
	b->top = tmp->next;
	b->size--;
	tmp->next = a->top;
	a->top = tmp;
	a->size++;
}

void	c_pb(t_stack *a, t_stack *b)
{
	t_list	*tmp;

	if (!a || a->size == 0)
		return ;
	tmp = a->top;
	a->top = tmp->next;
	a->size--;
	tmp->next = b->top;
	b->top = tmp;
	b->size++;
}
