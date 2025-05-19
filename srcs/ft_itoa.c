/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrobe-d <lgrobe-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:14:14 by lgrobe-d          #+#    #+#             */
/*   Updated: 2025/05/19 17:38:44 by lgrobe-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

static int	nlen(int n, int *sign)
{
	int	nb;
	int	len;

	nb = n;
	len = 0;
	*sign = 0;
	if (nb < 0)
	{
		nb *= -1;
		*sign = 1;
	}
	else if (nb == 0)
		len = 1;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		len;

	sign = 0;
	len = nlen(n, &sign);
	str = (char *)malloc(sizeof(char) * (len + sign +1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	str[len + sign] = '\0';
	if (n == -2147483648)
	{
		str[--len + sign] = '8';
		n /= 10;
	}
	if (sign)
		str[0] = '-';
	if (n < 0)
		n *= -1;
	while (n != 0)
	{
		str[--len + sign] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
