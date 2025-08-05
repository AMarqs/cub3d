/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:30:52 by albmarqu          #+#    #+#             */
/*   Updated: 2025/08/05 17:33:14 by albmarqu         ###   ########.fr       */
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

static int	find_map_start(t_game *game, int i)
{
	int	j;
	int	blank;

	blank = 0;
	while (game->data->map_data[i] && blank != 1)
	{
		j = 0;
		while (game->data->map_data[i] && game->data->map_data[i][j] != '\n'
			&& blank != 1)
		{
			if (game->data->map_data[i][j] != ' ')
				blank = 1;
			j++;
		}
		i++;
	}
	return (i - 1);
}

static void	extract_map_data(t_game *game, int start_index)
{
	int	i;

	game->data->map_size = game->data->file_rows - start_index;
	game->data->map = malloc((game->data->map_size + 1) * sizeof(char *));
	if (game->data->map == NULL)
		print_error("Error allocating memory\n", game);
	i = 0;
	while (game->data->map_data[start_index])
	{
		game->data->map[i] = ft_strdup(game->data->map_data[start_index]);
		start_index++;
		i++;
	}
	game->data->map[i] = NULL;
}

void	parse_map(t_game *game, int i)
{
	int	map_start;

	map_start = find_map_start(game, i);
	extract_map_data(game, map_start);
	parse_char(game);
	parse_player(game);
	parse_floor(game);
}
