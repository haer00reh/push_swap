/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haer-reh <haer-reh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:45:52 by haer-reh          #+#    #+#             */
/*   Updated: 2026/01/01 14:26:03 by haer-reh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac < 2)
		return (-1);
	if (ac >= 2)
	{
		begin_init(ac, av, &a, &b);
		if (a.size > 5)
		{
			find_lis(&a);
			apply_algorithms(&a, &b);
		}
		else
			simple_sort(&a, &b);
	}
	ft_lstclear(&a.top);
	ft_lstclear(&b.top);
	return (0);
}
