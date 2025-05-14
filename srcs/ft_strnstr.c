/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrobe-d <lgrobe-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:56:18 by lgrobe-d          #+#    #+#             */
/*   Updated: 2025/05/14 12:18:49 by lgrobe-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	char		*ptr;
	size_t		i;
	size_t		len;

	ptr = (char *)str;
	len = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (*ptr != '\0' && len < n)
	{
		if (*ptr == to_find[0])
		{
			i = 0;
			while (to_find[i] != '\0' && ptr[i] != '\0')
			{
				if (to_find[i] != ptr[i])
					break ;
				i++;
			}
			if (to_find[i] == '\0')
			{
				return (ptr);
			}
		}
		ptr++;
		len++;
	}
	return (NULL);
}
