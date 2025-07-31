/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 20:26:34 by albmarqu          #+#    #+#             */
/*   Updated: 2025/07/31 18:04:32 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	wrong_len(t_game *game, int row)
{
	if (ft_strlen(game->data->map[row]) > ft_strlen(game->data->map[row - 1]))
		return (1);
	return (0);
}

void	good_player(t_game *game, int row, int col)
{
	int	error;

	error = 0;
	if (row == 0 || wrong_len(game, row) || !game->data->map[row - 1][col]
		|| (game->data->map[row - 1][col] != '1'
		&& game->data->map[row - 1][col] != '0'))
		error = 1;
	else if (row == (game->data->map_size - 1) || !game->data->map[row + 1][col]
		|| (game->data->map[row + 1][col] != '1'
		&& game->data->map[row + 1][col] != '0'))
		error = 1;
	else if (col == 0 || !game->data->map[row][col - 1]
		|| (game->data->map[row][col - 1] != '1'
		&& game->data->map[row][col - 1] != '0'))
		error = 1;
	else if (!game->data->map[row][col + 1]
		|| (game->data->map[row][col + 1] != '1'
		&& game->data->map[row][col + 1] != '0'))
		error = 1;
	if (error == 1)
		print_error("Wrong player position\n", game);
}

void	parse_player(t_game *game)
{
	int	row;
	int	col;
	int	players;

	row = 0;
	players = 0;
	while (game->data->map[row])
	{
		col = 0;
		while (game->data->map[row][col])
		{
			if (game->data->map[row][col] == 'N'
				|| game->data->map[row][col] == 'S'
				|| game->data->map[row][col] == 'E'
				|| game->data->map[row][col] == 'W')
			{
				good_player(game, row, col);
				players++;
			}
			col++;
		}
		row++;
	}
	if (players != 1)
		print_error("Wrong number of players\n", game);
}
