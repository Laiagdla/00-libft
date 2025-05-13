/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrobe-d <lgrobe-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:35:58 by lgrobe-d          #+#    #+#             */
/*   Updated: 2025/05/13 15:48:36 by lgrobe-d         ###   ########.fr       */
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

void	test_isdigit(void)
{
	assert(ft_isdigit('5') == 1);
	assert(ft_isdigit('a') == 0);
	printf("ft_isdigit OK\n");
}

void	test_isalnum(void)
{
	assert(ft_isalnum('5') == 1);
	assert(ft_isalnum('a') == 1);
	assert(ft_isalnum('~') == 0);
	printf("ft_isalnum OK\n");
}

void	test_isascii(void)
{
	assert(ft_isascii('5') == 1);
	assert(ft_isascii('a') == 1);
	assert(ft_isascii('~') == 1);
	assert(ft_isascii(128) == 0);
	printf("ft_isascii OK\n");
}

void	test_isprint(void)
{
	assert(ft_isprint('5') == 1);
	assert(ft_isprint('a') == 1);
	assert(ft_isprint('~') == 1);
	assert(ft_isprint(' ') == 1);
	assert(ft_isprint(128) == 0);
	assert(ft_isprint(17) == 0);
	printf("ft_isprint OK\n");
}

void	test_strlen(void)
{
	assert(ft_strlen("hello") == 5);
	assert(ft_strlen("") == 0);
	printf("ft_strlen OK\n");
}

void	test_toupper(void)
{
	assert(ft_toupper('a') == 'A');
	assert(ft_toupper('4') == '4');
	printf("ft_toupper OK\n");
}

void	test_tolower(void)
{
	assert(ft_tolower('A') == 'a');
	assert(ft_tolower('4') == '4');
	printf("ft_tolower OK\n");
}

void	test_strchr(void)
{
	const char	*str = "hello";

	assert(ft_strchr(str, 'o') == str + 4);
	assert(ft_strchr(str, '\0') == str + 5);
	assert(ft_strchr(str, 'A') == NULL);
	printf("ft_strchr OK\n");
}

void	test_strrchr(void)
{
	const char	*str = "hello";

	assert(ft_strrchr(str, 'l') == str + 3);
	assert(ft_strrchr(str, '\0') == str + 5);
	assert(ft_strrchr(str, 'A') == NULL);
	printf("ft_strrchr OK\n");
}

void	test_memset(void)
{
	char	buffer[10];

	ft_memset(buffer, 'A', sizeof(buffer));
	assert(buffer[0] == 'A');
	assert(buffer[7] == 'A');
	printf("ft_memset OK\n");
}

void	test_memchr(void)
{
	const char	*buffer = "hello";
	char 		*ptr;

	ptr = ft_memchr(buffer, 'o', 5);
	assert(*ptr == 'o');
	assert(*ptr == buffer[4]);
	ptr = ft_memchr(buffer, 'z', 5);
	assert(ptr == NULL);
	printf("ft_memchr OK\n");
}


int	main(void)
{
	test_isalpha();
	test_isalpha();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_strlen();
	test_toupper();
	test_tolower();
	test_strchr();
	test_strrchr();
	test_memset();
	test_memchr();
	return (0);
}
