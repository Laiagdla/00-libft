/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrobe-d <lgrobe-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:58:18 by lgrobe-d          #+#    #+#             */
/*   Updated: 2025/05/19 12:31:36 by lgrobe-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

static size_t	ft_strmatch(char const *s1, char const *set)
{
	size_t	start;
	size_t	match;
	size_t	i;

	start = 0;
	while (s1[start])
	{
		i = 0;
		match = 0;
		while (set[i])
		{
			if (set[i] == s1[start])
				match++;
			i++;
		}
		if (match == 0)
			break ;
		start++;
	}
	return (start);
}

static size_t	ft_strrmatch(char const *s1, char const *set,
	size_t len, size_t start)
{
	size_t	match;
	size_t	i;

	while (s1[len -1] && len >= start)
	{
		i = 0;
		match = 0;
		while (set[i])
		{
			if (set[i] == s1[len -1])
				match++;
			i++;
		}
		if (match == 0)
			break ;
		len--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	start;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	start = ft_strmatch(s1, set);
	len = ft_strrmatch(s1, set, len, start);
	ptr = (char *)malloc(sizeof(char) * len - start +1);
	if (!ptr)
		return (NULL);
	ptr = ft_substr(s1, start, len - start);
	return (ptr);
}
