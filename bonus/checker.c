/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haer-reh <haer-reh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 11:54:43 by haer-reh          #+#    #+#             */
/*   Updated: 2025/12/31 15:44:01 by haer-reh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

static void	execute_command(t_stack *a, t_stack *b, char *analyse)
{
	if (ft_strcmp("pb", analyse))
		c_pb(a, b);
	else if (ft_strcmp("pa", analyse))
		c_pa(a, b);
	else if (ft_strcmp("ra", analyse))
		c_ra(a);
	else if (ft_strcmp("rb", analyse))
		c_rb(b);
	else if (ft_strcmp("rra", analyse))
		c_rra(a);
	else if (ft_strcmp("rrb", analyse))
		c_rrb(b);
	else if (ft_strcmp("rrr", analyse))
		c_rrr(a, b);
	else if (ft_strcmp("rr", analyse))
		c_rr(a, b);
	else if (ft_strcmp("sa", analyse))
		c_sa(a);
	else if (ft_strcmp("sb", analyse))
		c_sb(b);
	else if (ft_strcmp("ss", analyse))
		c_ss(a, b);
}

void	checker(t_stack *a, t_stack *b)
{
	char	*analyse;

	analyse = get_next_line(0);
	while (analyse)
	{
		execute_command(a, b, analyse);
		free(analyse);
		analyse = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac < 2)
		return (-1);
	begin_init(ac, av, &a, &b);
	checker(&a, &b);
	if (is_sorted(a.top))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
