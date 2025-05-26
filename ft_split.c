/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrobe-d <lgrobe-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:36:02 by lgrobe-d          #+#    #+#             */
/*   Updated: 2025/05/22 13:05:54 by lgrobe-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_array(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (0);
}

static size_t	split_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++ ;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static size_t	strlen_c(char const *ptr, char c)
{
	size_t	len;

	len = 0;
	while (ptr[len] && ptr[len] != c)
		len++;
	return (len);
}

static char	**arr_fill(char **dest, const char *s, char c, size_t count)
{
	const char	*src;
	size_t		index;
	size_t		len;

	src = s;
	index = 0;
	while (index < count)
	{
		while (*src == c)
			src++;
		len = strlen_c(src, c);
		dest[index] = (char *)malloc(sizeof(char) * (len + 1));
		if (!dest[index])
			return (free_array(dest, index));
		ft_strlcpy(dest[index], src, len +1);
		src += len;
		index++;
	}
	dest[index] = NULL;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char		**arr;
	size_t		count;

	if (!s)
		return (NULL);
	count = split_count(s, c);
	arr = (char **)malloc(sizeof(char *) * (count + 1));
	if (!arr)
		return (NULL);
	arr = arr_fill(arr, s, c, count);
	return (arr);
}
