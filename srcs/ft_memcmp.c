/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrobe-d <lgrobe-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:31:46 by lgrobe-d          #+#    #+#             */
/*   Updated: 2025/05/13 16:40:05 by lgrobe-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (*(unsigned char *)(s1 + i) == *(unsigned char *)(s2 + i) && i < n)
	{
		i++;
	}
	return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
}
