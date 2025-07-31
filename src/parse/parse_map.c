/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:30:52 by albmarqu          #+#    #+#             */
/*   Updated: 2025/07/30 18:54:47 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_char(t_game *game)
{
	int		row;
	int		col;
	char	box;

	row = 0;
	box = 0;
	while (game->data->map[row])
	{
		col = 0;
		while (game->data->map[row] && game->data->map[row][col])
		{
			box = game->data->map[row][col];
			if (box != '1' && box != '0' && box != 'N' && box != 'S'
				&& box != 'W' && box != 'E' && box != ' ' && box != '\t'
				&& box != '\n')
				print_error("Wrong map characters\n", game);
			col++;
		}
		row++;
	}
}

void	parse_map(t_game *game, int i)
{
	int		j;
	int		blank;

	blank = 0;
	while (game->data->map_data[i] && blank != 1)
	{
		j = 0;
		while (game->data->map_data[i]
			&& game->data->map_data[i][j] != '\n' && blank != 1)
		{
			if (game->data->map_data[i][j] != ' ')
				blank = 1;
			j++;
		}
		i++;
	}
	i--;
	game->data->map = malloc((game->data->file_rows - i + 1) * sizeof(char *));
	if (game->data->map == NULL)
		print_error("Error allocating memory\n", game);
	j = 0;
	while (game->data->map_data[i])
	{
		game->data->map[j] = ft_strdup(game->data->map_data[i]);
		i++;
		j++;
	}
	game->data->map[j] = NULL;
	parse_char(game);
	parse_player(game);
	parse_floor(game);
}
