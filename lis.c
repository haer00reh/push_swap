/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haer-reh <haer-reh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:58:53 by haer-reh          #+#    #+#             */
/*   Updated: 2025/12/26 11:35:28 by haer-reh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*stack_to_array(t_stack *a)
{
	int		*arr;
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = a->top;
	arr = malloc(sizeof(int) * a->size);
	if (!arr)
		return (NULL);
	while (tmp)
	{
		arr[i] = tmp->index;
		tmp = tmp->next;
		i++;
	}
	return (arr);
}

static void	compute_lis(int *arr, int size, int *prev, int *lis)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		prev[i] = -1;
		lis[i] = 1;
		j = 0;
		while (j < i)
		{
			if (arr[j] < arr[i] && lis[j] + 1 > lis[i])
			{
				lis[i] = lis[j] + 1;
				prev[i] = j;
			}
			j++;
		}
		i++;
	}
}

static int	find_lis_end(int *lis, int size)
{
	int	i;
	int	max;
	int	pos;

	i = 0;
	max = 0;
	pos = 0;
	while (i < size)
	{
		if (lis[i] > max)
		{
			max = lis[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

static void	mark_lis(t_stack *a, int *arr, int *prev, int pos)
{
	t_list	*tmp;

	while (pos != -1)
	{
		tmp = a->top;
		while (tmp)
		{
			if (tmp->index == arr[pos])
			{
				tmp->in_lis = 1;
				break ;
			}
			tmp = tmp->next;
		}
		pos = prev[pos];
	}
}

void	find_lis(t_stack *a)
{
	int	*arr;
	int	*lis;
	int	*prev;
	int	end;

	arr = stack_to_array(a);
	if (!arr)
		return ;
	lis = malloc(sizeof(int) * a->size);
	prev = malloc(sizeof(int) * a->size);
	if (!lis || !prev)
	{
		free(arr);
		free(lis);
		free(prev);
		return ;
	}
	compute_lis(arr, a->size, prev, lis);
	end = find_lis_end(lis, a->size);
	mark_lis(a, arr, prev, end);
	free(arr);
	free(lis);
	free(prev);
}
