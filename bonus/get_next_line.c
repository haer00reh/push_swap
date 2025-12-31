/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haer-reh <haer-reh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:40:26 by haer-reh          #+#    #+#             */
/*   Updated: 2025/12/31 14:20:57 by haer-reh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static	char	*save_rest(char *str)
{
	size_t	i;
	char	*rstr;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] && str[i] == '\n')
		i++;
	if (!str[i])
		return (NULL);
	rstr = ft_strdup(&str[i]);
	return (rstr);
}

static char	*read_to_table(int fd, char *table)
{
	char	*buffer;
	ssize_t	bytes_read;
	char	*tmp;

	buffer = (char *)malloc(sizeof(char) * (5 + 1));
	if (!buffer)
		return (NULL);
	if (!table)
		table = ft_strdup("");
	while (!ft_strchr(table, '\n'))
	{
		bytes_read = read(fd, buffer, 5);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		tmp = table;
		table = ft_strjoin(table, buffer);
		free(tmp);
	}
	free(buffer);
	return (table);
}

static char	*get_line_from_table(char **table)
{
	char	*line;
	char	*tmp;

	if (ft_strchr(*table, '\n'))
	{
		line = extract_n(*table);
		tmp = *table;
		*table = save_rest(*table);
		free(tmp);
		return (line);
	}
	else if (*table && **table)
	{
		line = extract_n(*table);
		free(*table);
		*table = NULL;
		return (line);
	}
	free(*table);
	*table = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*table;

	if (fd < 0 || 5 <= 0)
		return (NULL);
	table = read_to_table(fd, table);
	return (get_line_from_table(&table));
}
