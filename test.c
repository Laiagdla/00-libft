/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrobe-d <lgrobe-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:35:58 by lgrobe-d          #+#    #+#             */
/*   Updated: 2025/05/14 15:08:24 by lgrobe-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "includes/libft.h"

int	test_isalpha(void)
{
	assert(ft_isalpha('a') == 1);
	assert(ft_isalpha('2') == 0);
	return(0);
}

int	test_isdigit(void)
{
	assert(ft_isdigit('5') == 1);
	assert(ft_isdigit('a') == 0);
	return(0);
}

int	test_isalnum(void)
{
	assert(ft_isalnum('5') == 1);
	assert(ft_isalnum('a') == 1);
	assert(ft_isalnum('~') == 0);
	return(0);
}

int	test_isascii(void)
{
	assert(ft_isascii('5') == 1);
	assert(ft_isascii('a') == 1);
	assert(ft_isascii('~') == 1);
	assert(ft_isascii(128) == 0);
	return(0);
}

int	test_isprint(void)
{
	assert(ft_isprint('5') == 1);
	assert(ft_isprint('a') == 1);
	assert(ft_isprint('~') == 1);
	assert(ft_isprint(' ') == 1);
	assert(ft_isprint(128) == 0);
	assert(ft_isprint(17) == 0);
	return(0);}

int	test_strlen(void)
{
	assert(ft_strlen("hello") == 5);
	assert(ft_strlen("") == 0);
	return(0);
}

int	test_toupper(void)
{
	assert(ft_toupper('a') == 'A');
	assert(ft_toupper('4') == '4');
	return(0);
}

int	test_tolower(void)
{
	assert(ft_tolower('A') == 'a');
	assert(ft_tolower('4') == '4');
	return(0);
}

int	test_strchr(void)
{
	const char	*str = "hello";

	assert(ft_strchr(str, 'o') == str + 4);
	assert(ft_strchr(str, '\0') == str + 5);
	assert(ft_strchr(str, 'A') == NULL);
	return(0);
}

int	test_strrchr(void)
{
	const char	*str = "hello";

	assert(ft_strrchr(str, 'l') == str + 3);
	assert(ft_strrchr(str, '\0') == str + 5);
	assert(ft_strrchr(str, 'A') == NULL);
	return(0);
}

int	test_memset(void)
{
	char	buffer[10];

	ft_memset(buffer, 'A', sizeof(buffer));
	assert(buffer[0] == 'A');
	assert(buffer[7] == 'A');
	return(0);
}

int	test_memchr(void)
{
	const char	*buffer = "hello";
	char 		*ptr;

	ptr = ft_memchr(buffer, 'o', 5);
	assert(*ptr == 'o');
	assert(*ptr == buffer[4]);
	ptr = ft_memchr(buffer, 'z', 5);
	assert(ptr == NULL);
	return(0);
}

int	test_memcmp(void)
{
	const char	*s1 = "hello";
	const char 	*s2 = "help";

	assert(ft_memcmp(s1, s2, 5) == -4);
	assert(ft_memcmp(s1, s1, 5) == 0);
	assert(ft_memcmp(s2, s1, 5) == 4);
	return(0);
}

int	test_memcpy(void)
{
	const char	*src = "hello";
	char 		*dest = malloc(10);
	char		*ptr;
	ptr = ft_memcpy(dest, src, 5);

	assert(*ptr == 'h');
	assert(*(ptr + 4) == 'o');
	return(0);
}

int	test_memmove(void)
{
	const char	*src = "hello";
	char 		*dest = malloc(10);
	char		*ptr;
	ptr = ft_memmove(dest, src, 5);

	assert(*ptr == 'h');
	assert(*(ptr + 4) == 'o');
	return(0);
}

int	test_strncmp(void)
{
	const char	*s1 = "hello";
	const char 	*s2 = "help";

	assert(ft_strncmp(s1, s2, 5) == -4);
	assert(ft_strncmp(s1, s1, 5) == 0);
	assert(ft_strncmp(s2, s1, 5) == 4);
	return(0);
}

int	test_strnstr(void)
{
	const char	*haystack = "one more line of code";
	const char	*needle = "lin";
	char		*ptr;

	ptr = ft_strnstr(haystack, needle, 2);
	assert(ptr == NULL);
	ptr = ft_strnstr(haystack, needle, 20);
	assert(ptr == haystack + 9);
	return (0);
}

int	test_strlcpy(void)
{
	const char	*src = "hello";
	char 		*dest = malloc(10);
	ft_strlcpy(dest, src, 6);

	assert(dest[0] == 'h');
	assert(dest[4] == 'o');
	return(0);
}


#define GREEN  "\e[32m"
#define RESET "\e[0m"

int	main(void)
{
	printf(GREEN "%d ft_isalpha OK \n" RESET, test_isalpha());
	printf(GREEN "%d ft_isalnum OK\n" RESET, test_isalnum());
	printf(GREEN "%d ft_isascii OK\n" RESET, test_isascii());
	printf(GREEN "%d ft_isprint OK\n" RESET, test_isprint());
	printf(GREEN "%d ft_strlen OK\n" RESET, test_strlen());
	printf(GREEN "%d ft_toupper OK\n" RESET, test_toupper());
	printf(GREEN "%d ft_tolower OK\n" RESET, test_tolower());
	printf(GREEN "%d ft_strchr OK\n" RESET, test_strchr());
	printf(GREEN "%d ft_strrchr OK\n" RESET, test_strrchr());
	printf(GREEN "%d ft_memset OK\n" RESET, test_memset());
	printf(GREEN "%d ft_memchr OK\n" RESET, test_memchr());
	printf(GREEN "%d ft_memcmp OK\n" RESET, test_memcmp());
	printf(GREEN "%d ft_memcpy OK\n" RESET, test_memcpy());
	printf(GREEN "%d ft_memmove OK\n" RESET, test_memmove());
	printf(GREEN "%d ft_strncmp OK\n" RESET, test_strncmp());
	printf(GREEN "%d ft_strnstr OK\n" RESET, test_strnstr());
	printf(GREEN "%d ft_strlcpy OK\n" RESET, test_strlcpy());
	return (0);
}
