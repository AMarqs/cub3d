/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 20:26:34 by albmarqu          #+#    #+#             */
/*   Updated: 2025/07/21 20:27:15 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	good_player(t_data *data, int row, int col)
{
	int	error;

	error = 0;
	if (!data->map[row - 1][col]
		|| (data->map[row - 1][col] != '1' && data->map[row - 1][col] != '0'))
		error = 1;
	else if (!data->map[row + 1][col]
		|| (data->map[row + 1][col] != '1' && data->map[row + 1][col] != '0'))
		error = 1;
	else if (!data->map[row][col - 1]
		|| (data->map[row][col - 1] != '1' && data->map[row][col - 1] != '0'))
		error = 1;
	else if (!data->map[row][col + 1]
		|| (data->map[row][col + 1] != '1' && data->map[row][col + 1] != '0'))
		error = 1;
	if (error == 1)
		print_error("Wrong player position\n", data);
}

void	parse_player(t_data *data)
{
	int	row;
	int	col;
	int	players;

	row = 0;
	players = 0;
	while (data->map[row])
	{
		col = 0;
		while (data->map[row][col])
		{
			if (data->map[row][col] == 'N' || data->map[row][col] == 'S'
				|| data->map[row][col] == 'W' || data->map[row][col] == 'E')
			{
				good_player(data, row, col);
				players++;
			}
			col++;
		}
		row++;
	}
	if (players != 1)
		print_error("Wrong number of players\n", data);
	write(1, "Good player\n", 12);
}
