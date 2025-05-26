/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrobe-d <lgrobe-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:12:34 by lgrobe-d          #+#    #+#             */
/*   Updated: 2025/05/23 15:35:36 by lgrobe-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i_start;
	size_t	i_end;
	char	*substr;

	if (!s1 || !set)
		return (NULL);
	i_start = 0;
	i_end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[i_start]))
	{
		if (!s1[i_start])
			break ;
		i_start++;
	}
	if (i_start == i_end + 1)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[i_end]))
		i_end--;
	substr = ft_substr(s1, i_start, i_end - i_start + 1);
	if (!substr)
		return (NULL);
	return (substr);
}
