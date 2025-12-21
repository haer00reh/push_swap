/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackOperations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haer-reh <haer-reh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:01:32 by haer-reh          #+#    #+#             */
/*   Updated: 2025/12/20 13:37:30 by haer-reh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
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
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
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
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(&a);
	sb(&b);
	write(1, "ss\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	t_list *tmp;

	if (!b || b->size == 0)
		return ;
	tmp = b->top;
	b->top = tmp->next;
	b->size--;
	
	tmp->next = a->top;
	a->top = tmp;
	a->size++;
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	t_list *tmp;

	if (!a || a->size == 0)
		return ;
	tmp = a->top;
	a->top = tmp->next;
	a->size--;
	tmp->next = b->top;
	b->top = tmp;
	b->size++;
	write(1, "pb\n", 3);
}
