/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joritz-m <joritz-m@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:33:58 by albmarqu          #+#    #+#             */
/*   Updated: 2025/07/09 13:10:48 by joritz-m             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

static char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;

	if (s1 == NULL)
		return (NULL);
	dst = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	ft_strcpy(dst, s1);
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	i;
	size_t	j;
	size_t	len1;

	i = -1;
	j = 0;
	len1 = ft_strlen(s1);
	dst = (char *)malloc((len1 + ft_strlen(s2) + 1) * sizeof(char));
	if (dst == NULL)
	{
		free ((char *)s1);
		return (NULL);
	}
	while (++i < len1)
		dst[i] = s1[i];
	while (j < ft_strlen(s2))
	{
		dst[i] = s2[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	free ((char *)s1);
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ss;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (NULL);
	if ((start + len) > ft_strlen(s))
		len = ft_strlen(s) - start;
	ss = (char *)malloc((len + 1) * sizeof(char));
	if (ss == NULL)
		return (NULL);
	while (s[start + i] && len > 0)
	{
		ss[i] = s[start + i];
		len--;
		i++;
	}
	ss[i] = '\0';
	return (ss);
}