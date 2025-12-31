/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haer-reh <haer-reh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:39:56 by haer-reh          #+#    #+#             */
/*   Updated: 2025/12/31 14:20:46 by haer-reh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		len;
	int		i;

	len = 0;
	while (s[len])
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

char	*extract_n(char *str)
{
	size_t	len;
	char	*nstr;
	size_t	i;

	if (!str)
		return (NULL);
	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	nstr = malloc(sizeof(char) * (len + 1));
	if (!nstr)
		return (NULL);
	nstr[len] = '\0';
	i = 0;
	while (i < len)
	{
		nstr[i] = str[i];
		i++;
	}
	return (nstr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			len;
	char			*str;

	if (!s1)
		return (ft_strdup(s2));
	len = ft_strlen((char *)s1);
	len += ft_strlen((char *)s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len = 0;
	while (*s1)
	{
		str[len] = *s1;
		s1++;
		len++;
	}
	while (*s2)
	{
		str[len] = *s2;
		s2++;
		len++;
	}
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}
