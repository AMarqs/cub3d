/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:46:09 by albmarqu          #+#    #+#             */
/*   Updated: 2025/07/29 15:34:50 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_pos(t_data *data, t_init	*init)
{
	int	row;
	int	col;

	row = 0;
///
	int i = 0;
	printf("\nMAPA\n");
	while (data->map[i])
		printf("%s", data->map[i++]);
	printf("\n");
///
	while (data->map[row])
	{
		col = 0;
		while (data->map[row][col])
		{
			if (data->map[row][col] == 'N' || data->map[row][col] == 'S'
				|| data->map[row][col] == 'E' || data->map[row][col] == 'W')
			{
				init->pos_y = row;
				init->pos_x = col;
			}
			if (data->map[row][col] == 'N')
				init->pos_dir = 1;
			else if (data->map[row][col] == 'S')
				init->pos_dir = 2;
			else if (data->map[row][col] == 'E')
				init->pos_dir = 3;
			else if (data->map[row][col] == 'W')
				init->pos_dir = 4;
			col++;
		}
		row++;
	}
	// printf("Y = %d\n", init->pos_y);
	// printf("X = %d\n", init->pos_x);
	// printf("DIR = %d\n", init->pos_dir);
}
