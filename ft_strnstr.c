/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrobe-d <lgrobe-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:56:18 by lgrobe-d          #+#    #+#             */
/*   Updated: 2025/05/23 11:26:40 by lgrobe-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;

	j = 0;
	if (!*little)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (big[j] && j < len)
	{
		i = 0;
		if (big[j] == little[i])
		{
			while ((little[i] && big[j + i]) && (j + i < len))
			{
				if (little[i] != big[j + i])
					break ;
				i++;
			}
			if (little[i] == '\0')
				return ((char *)&big[j]);
		}
		j++;
	}
	return (NULL);
}
