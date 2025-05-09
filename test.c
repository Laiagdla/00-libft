/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrobe-d <lgrobe-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:35:58 by lgrobe-d          #+#    #+#             */
/*   Updated: 2025/05/09 13:24:21 by lgrobe-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <assert.h>
#include "includes/libft.h"

void	test_isalpha(void)
{
	assert(ft_isalpha('a') == 1);
	assert(ft_isalpha('2') == 0);
	printf("ft_isalpha OK\n");
}

int	main(void)
{
	test_isalpha();
	return (0);
}
