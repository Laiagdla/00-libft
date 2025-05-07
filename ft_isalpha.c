/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrobe-d <lgrobe-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:44:18 by lgrobe-d          #+#    #+#             */
/*   Updated: 2025/05/07 14:04:57 by lgrobe-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_alpha(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	else if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_str_is_alpha(char *str)
{
	int	i;
	int	cond;

	cond = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_char_is_alpha(str[i]))
		{
			cond++;
		}
		i++;
	}
	if (cond == i)
	{
		return (1);
	}
	return (0);
}
