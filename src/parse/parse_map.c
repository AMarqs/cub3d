/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:30:52 by albmarqu          #+#    #+#             */
/*   Updated: 2025/07/18 13:23:12 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_char(t_data *data)
{
	int		row;
	int		col;

	row = 0;
	while (data->map[row])
	{
		col = 0;
		while (data->map[row][col])
		{
			if (data->map[row][col] != '1' && data->map[row][col] != '0'
				&& data->map[row][col] != 'N' && data->map[row][col] != 'S'
				&& data->map[row][col] != 'W' && data->map[row][col] != 'E'
				&& data->map[row][col] != ' ' )
			{
				write(2, "Error\nWrong map characters\n", 27);
				exit(EXIT_FAILURE);
			}
		}
		row++;
	}
}

void	parse_player(t_data *data)
{
	int		row;
	int		col;
	t_count	*count;

	row = 0;
	count->total = 0;
	while (data->map[row])
	{
		col = 0;
		while (data->map[row][col])
		{
			if (data->map[row][col] == 'N')
				count->total++;
			if (data->map[row][col] == 'S')
				count->total++;
			if (data->map[row][col] == 'W')
				count->total++;
			if (data->map[row][col] == 'E')
				count->total++;
		}
		row++;
	}
	if (count->total != 1)
	{
		write(2, "Error\nWrong number of players\n", 30);
		exit(EXIT_FAILURE);
	}
}

void	correct_floor(t_data *data, int row, int col)
{
	if (data->map[row - 1][col] == 0)

	if (data->map[row + 1][col] == 0)

	if (data->map[row][col - 1] == 0)
	
	if (data->map[row][col + 1] == 0)
	
}

void	parse_floor(t_data *data)
{
	int	row;
	int col;

	row = 0;
	col = 0;
	while (data->map[row][col])
	{
		if (data->map[row][col] == 0)
		{
			
		}
	}
}

void	parse_map(t_data *data, int i)
{
	int		j;
	int		blank;

	blank = 0;
	while (data->map_data[i] && blank != 1)
	{
		j = 0;
		while (data->map_data[i] && data->map_data[i][j] != '\n' && blank != 1)
		{
			if (data->map_data[i][j] != ' ')
				blank = 1;
			j++;
		}
		i++;
	}
	i--;
	data->map = malloc((i + 1) * sizeof(char *));
	if (data->map == NULL)
		error_alocating(data);
	j = 0;
	while (data->map_data[i])
	{
		data->map[j] = data->map_data[i];
		i++;
		j++;
	}
	parse_char(data);
	parse_player(data);
	parse_floor(data);
///
	i = 0;
	printf("\nREAL MAPA\n");
	while (i < j)
		printf("%s", data->map[i++]);
	printf("\n");
///
}
