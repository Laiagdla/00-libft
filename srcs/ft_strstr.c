/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrobe-d <lgrobe-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:56:18 by lgrobe-d          #+#    #+#             */
/*   Updated: 2025/05/14 12:08:08 by lgrobe-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strstr(const char *str, const char *to_find)
{
	char	*ptr;
	int		pos2;

	ptr = (char *)str;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (*ptr != '\0')
	{
		if (*ptr == to_find[0])
		{
			pos2 = 0;
			while (to_find[pos2] != '\0' && ptr[pos2] != '\0')
			{
				if (to_find[pos2] != ptr[pos2])
					break ;
				pos2++;
			}
			if (to_find[pos2] == '\0')
			{
				return (ptr);
			}
		}
		ptr++;
	}
	return (NULL);
}
