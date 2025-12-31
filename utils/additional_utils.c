/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haer-reh <haer-reh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 15:27:45 by haer-reh          #+#    #+#             */
/*   Updated: 2025/12/30 14:01:43 by haer-reh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	isort(int *arr, int len)
{
	int (i), (j), (k);
	i = 1;
	while (i < len)
	{
		k = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > k)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = k;
		i++;
	}
}

void	assign_index(t_stack *a, int *arr)
{
	t_list	*tmp;
	int		i;

	tmp = a->top;
	while (tmp)
	{
		i = 0;
		while (i < a->size)
		{
			if (arr[i] == tmp->content)
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

void	t_index(t_stack *a)
{
	int		*arr;
	int		i;
	t_list	*tmp;

	tmp = a->top;
	i = 0;
	arr = malloc(sizeof(int) * (a->size));
	if (!arr)
		return ;
	while (i < a->size)
	{
		arr[i] = tmp->content;
		i++;
		tmp = tmp->next;
	}
	isort(arr, a->size);
	assign_index(a, arr);
	free(arr);
}
