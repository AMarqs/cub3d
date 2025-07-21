/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:30:52 by albmarqu          #+#    #+#             */
/*   Updated: 2025/07/21 20:26:47 by albmarqu         ###   ########.fr       */
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
		while (data->map[row] && data->map[row][col])
		{
			if (data->map[row][col] != '1' && data->map[row][col] != '0'
				&& data->map[row][col] != 'N' && data->map[row][col] != 'S'
				&& data->map[row][col] != 'W' && data->map[row][col] != 'E'
				&& data->map[row][col] != ' ' && data->map[row][col] != '\t'
				&& data->map[row][col] != '\n')
				print_error("Wrong map characters\n", data);
			col++;
		}
		row++;
	}
	write(1, "Good map characters\n", 20);
}

void	correct_floor(t_data *data, int row, int col)
{
	if (!data->map[row][col]
		|| (data->map[row][col] != '1' && data->map[row][col] != '0'
		&& data->map[row][col] != 'N' && data->map[row][col] != 'S'
		&& data->map[row][col] != 'W' && data->map[row][col] != 'E'))
		print_error("Incorrect floor position\n", data);
}

void	parse_floor(t_data *data)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (data->map[row])
	{
		col = 0;
		if (!data->map[row][col] || !ft_strncmp(data->map[row], "\n", 1))
			print_error("Splitted map\n", data);
		while (data->map[row][col])
		{
			if (data->map[row][col] == 0)
			{
				correct_floor(data, (row - 1), col);
				correct_floor(data, (row + 1), col);
				correct_floor(data, row, (col - 1));
				correct_floor(data, row, (col + 1));
			}
			col++;
		}
		row++;
	}
	write(1, "Good floor (0)\n", 15);
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
	data->map = malloc((data->file_rows - i + 1) * sizeof(char *));
	if (data->map == NULL)
		print_error("Error allocating memory\n", data);
	j = 0;
	while (data->map_data[i])
	{
		data->map[j] = ft_strdup(data->map_data[i]);
		i++;
		j++;
	}
///
	i = 0;
	printf("\nREAL MAPA\n");
	while (i < j)
		printf("%s", data->map[i++]);
	printf("\n");
///
	parse_char(data);
	parse_player(data);
	parse_floor(data);
}
