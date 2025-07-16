/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:35:48 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/12/03 10:58:26 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	check_len(char *str, int len)
{
	if (ft_strlen_gnl(str) != len)
		return (false);
	return (true);
}

int	count_char_in_str(char *str, char c)
{
	int	res;

	res = 0;
	if (check_strchr_gnl(str, c))
	{
		while (*str)
		{
			if (*str == c)
				res++;
			str++;
		}
	}
	return (res);
}

bool	all_chars_same(char *str, char c)
{
	if (!str)
		return (false);
	while (*str)
	{
		if (*str != c && *str != '\n')
			return (false);
		str++;
	}
	return (true);
}

bool	check_strchr_gnl(char *str, char chr)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == chr)
			return (true);
		i++;
	}
	return (false);
}
