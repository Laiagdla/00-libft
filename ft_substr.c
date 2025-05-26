/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrobe-d <lgrobe-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:02:16 by lgrobe-d          #+#    #+#             */
/*   Updated: 2025/05/23 15:06:22 by lgrobe-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	real_len;

	if (!s)
		return (NULL);
	real_len = ft_strlen(s);
	if (start >= real_len)
		return (ft_strdup(""));
	if (len > real_len - start)
		len = real_len - start;
	ptr = (char *)malloc(sizeof(char) * len +1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, &s[start], len +1);
	return (ptr);
}
