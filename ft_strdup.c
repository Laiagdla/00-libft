/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrobe-d <lgrobe-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:19:52 by lgrobe-d          #+#    #+#             */
/*   Updated: 2025/05/22 12:49:10 by lgrobe-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(s) + 1;
	ptr = (char *)malloc(sizeof(char) * len);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s, len);
	return (ptr);
}
