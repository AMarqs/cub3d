/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joritz-m <joritz-m@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:31:00 by albmarqu          #+#    #+#             */
/*   Updated: 2025/07/09 13:09:57 by joritz-m             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	char	c1;
	char	*s1;

	c1 = (char)c;
	s1 = (char *)s;
	if (s == NULL)
		return (NULL);
	while (*s1)
	{
		if (*s1 == c1)
			return (s1);
		s1++;
	}
	if (c1 == '\0')
		return (s1);
	return (NULL);
}

void	freee(char **s)
{
	if (*s == NULL)
		return ;
	free(*s);
	*s = NULL;
}

int	reading(int fd, char **storage)
{
	char		next_line[BUFFER_SIZE + 1];
	int			num_read;

	while (1)
	{
		num_read = read (fd, next_line, BUFFER_SIZE);
		if (num_read <= 0)
			break ;
		next_line[num_read] = '\0';
		*storage = ft_strjoin(*storage, next_line);
		if (ft_strchr(next_line, '\n'))
			break ;
	}
	return (num_read);
}

void	cleaning(char *join, char **storage, char **new_line)
{
	size_t	len_join;

	len_join = ft_strlen(join);
	if (*new_line == NULL)
	{
		freee (&join);
		return ;
	}
	*storage = ft_substr(join, ft_strchr(join, '\n') - join + 1, len_join);
	if (storage == NULL && (join[len_join - 1] != '\n'
			|| join[len_join - 1] == join[len_join - 2]))
		freee (new_line);
	freee (&join);
}

char	*get_next_line(int fd)
{
	static char	*storage[OPEN_MAX];
	char		*join;
	char		*new_line;
	int			num_read;

	num_read = reading(fd, &storage[fd]);
	join = ft_strdup(storage[fd]);
	if (num_read == -1)
	{
		freee (&storage[fd]);
		free (join);
		return (NULL);
	}
	if (ft_strchr(join, '\n') == NULL)
	{
		freee (&storage[fd]);
		return (join);
	}
	new_line = ft_substr(join, 0, ft_strchr(join, '\n') - join + 1);
	freee (&storage[fd]);
	cleaning (join, &storage[fd], &new_line);
	return (new_line);
}
/*
int	main(void)
{
	const char	*camino;
	int			flags;
	int			fd;
	char		*next_line;

	camino = "hola.txt";
	flags = O_RDONLY;
	fd = open (camino, flags);
	while((next_line = get_next_line(fd)))
		printf("%s",next_line);
	return (0);
}
*/