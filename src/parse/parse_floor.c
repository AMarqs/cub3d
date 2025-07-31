/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:43:59 by albmarqu          #+#    #+#             */
/*   Updated: 2025/07/31 13:56:38 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	correct_floor(t_game *game, int row, int col)
{
	char	box;

	box = 0;
	if (row < 0 || col < 0 || !game->data->map[row]
		|| !game->data->map[row][col])
		print_error("Map not closed by walls\n", game);
	box = game->data->map[row][col];
	if (box != '1' && box != '0' && box != 'N' && box != 'S' && box != 'E'
		&& box != 'W')
		print_error("Map not closed by walls\n", game);
}

void	new_line(t_game *game, int row)
{
	int	okay;

	okay = 0;
	if (!game->data->map[row][0])
		print_error("Splitted map\n", game);
	if (!ft_strncmp(game->data->map[row], "\n", 1))
	{
		while (game->data->map[row] && row < game->data->file_rows)
		{
			if (ft_strncmp(game->data->map[row], "\n", 1))
				okay = 1;
			row++;
		}
	}
	if (okay == 1)
		print_error("Splitted map\n", game);
}

void	parse_floor(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (game->data->map[row])
	{
		col = 0;
		new_line(game, row);
		while (game->data->map[row][col])
		{
			if (game->data->map[row][col] == '0'
				|| game->data->map[row][col] == 'N'
				|| game->data->map[row][col] == 'S'
				|| game->data->map[row][col] == 'E'
				|| game->data->map[row][col] == 'W')
			{
				correct_floor(game, (row - 1), col);
				correct_floor(game, (row + 1), col);
				correct_floor(game, row, (col - 1));
				correct_floor(game, row, (col + 1));
			}
			col++;
		}
		row++;
	}
}
