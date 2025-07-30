/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:29:47 by jortiz-m          #+#    #+#             */
/*   Updated: 2025/07/30 11:30:32 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_close_with_error(t_game *game)
{
	if (game)
	{
		ft_free_map(game);
		if (game->mlx)
			mlx_terminate(game->mlx);
		free(game);
	}
	exit(EXIT_FAILURE);
}

char	**ft_cpy_matrix(char **src)
{
	char	**dst;
	int		i;

	i = 0;
	if (!src || !src[i])
		return (NULL);
	while (src[i])
		i++;
	dst = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (src[i])
	{
		dst[i] = ft_strdup(src[i]);
		i++;
	}
	dst[i] = NULL;
	return (dst);
}

int	ft_is_space(const char *str, int counter)
{
	if ((str[counter] >= 9 && str[counter] <= 13) || str[counter] == 32)
		return (1);
	return (0);
}
