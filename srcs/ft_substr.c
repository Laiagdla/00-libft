/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrobe-d <lgrobe-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:02:16 by lgrobe-d          #+#    #+#             */
/*   Updated: 2025/05/16 13:25:36 by lgrobe-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * len +1);
	if (!ptr)
		return (NULL);
	if (start >= ft_strlen(s))
		return (*ptr = '\0', ptr);
	ft_strlcpy(ptr, &s[start], len +1);
	return (ptr);
}
