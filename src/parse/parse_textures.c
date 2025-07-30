/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:08:38 by albmarqu          #+#    #+#             */
/*   Updated: 2025/07/10 13:08:38 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	open_texture_file(char *path, t_game *game)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nNo such file or directory: ", 32);
		write(2, path, ft_strlen(path));
		write(2, "\n", 1);
		frees(game);
		exit(EXIT_FAILURE);
	}
	close(fd);
}

void	parse_direction(t_game *game, char *dir, char *path)
{
	int		len;
	char	*aux;

	len = ft_strlen(dir);
	aux = ft_substr(dir, 2, len);
	path = ft_strtrim(aux, " \n");
	free(aux);
	open_texture_file(path, game);
}

void	parse_texture(char *map, t_game *game)
{
	if (map[0] == 'N' && map[1] == 'O')
	{
		parse_direction(game, map, game->data->no_texture);
		game->data->count->count_no++;
	}
	else if (map[0] == 'S' && map[1] == 'O')
	{
		parse_direction(game, map, game->data->so_texture);
		game->data->count->count_so++;
	}
	else if (map[0] == 'E' && map[1] == 'A')
	{
		parse_direction(game, map, game->data->ea_texture);
		game->data->count->count_ea++;
	}
	else if (map[0] == 'W' && map[1] == 'E')
	{
		parse_direction(game, map, game->data->we_texture);
		game->data->count->count_we++;
	}
}
