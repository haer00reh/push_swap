/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haer-reh <haer-reh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:42:35 by haer-reh          #+#    #+#             */
/*   Updated: 2025/12/17 18:24:57 by haer-reh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*copy_word(char *str, int len)
{
	char	*s;
	int		i;

	i = 0;
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	s[len] = '\0';
	while (*str && i < len)
	{
		s[i] = str[i];
		i++;
	}
	return (s);
}

long	ft_atoi(char *str)
{
	long (sign), (nbr);
	nbr = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr = (nbr * 10) + (*str - '0');
		str++;
	}
	return (nbr * sign);
}

int	count_words(char *str, char sep)
{
	int (counter), (i);
	counter = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == sep)
			i++;
		if (str[i])
			counter++;
		while (str[i] && (str[i] != sep))
			i++;
	}
	return (counter);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	return ;
}

char	**ft_split(char *str, char sep)
{
	char	**split;

	int (words), (i), (len);
	words = count_words(str, sep);
	split = malloc(sizeof(char *) * (words));
	if (!split)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str && *str == sep)
			str++;
		if (*str == '\0')
			break ;
		len = 0;
		while (*(str + len) && *(str + len) != sep)
			len++;
		split[i] = copy_word(str, len);
		if (!split[i])
			return (free_split(split), NULL);
		i++;
		str += len;
	}
	split[i] = NULL;
	return (split);
}
