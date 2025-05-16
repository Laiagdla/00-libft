/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrobe-d <lgrobe-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:56:18 by lgrobe-d          #+#    #+#             */
/*   Updated: 2025/05/16 11:50:24 by lgrobe-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t		i;
	size_t		len;

	len = 0;
	if (to_find[0] == '\0' || n == 0)
		return ((char *)str);
	while (str[len] != '\0' && len < n)
	{
		i = 0;
		if (str[len] == to_find[i])
		{
			while ((to_find[i] != '\0' && str[len + i] != '\0')
				&& (len + i < n))
			{
				if (to_find[i] != str[len + i])
					break ;
				i++;
			}
			if (to_find[i] == '\0')
				return ((char *)&str[len]);
		}
		len++;
	}
	return (NULL);
}
