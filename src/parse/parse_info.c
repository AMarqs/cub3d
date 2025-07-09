/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alba <alba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:57:52 by albmarqu          #+#    #+#             */
/*   Updated: 2025/07/09 13:12:59 by alba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	texture_type(char **map, int i, int count)
{
	if (map[i][0] == 'N' && map[i][1] == 'O')
	{
		parse_no(map[i]);
		count++;
	}
	else if (map[i][0] == 'S' && map[i][1] == 'O')
	{
		parse_so(map[i]);
		count++;
	}
	else if (map[i][0] == 'W' && map[i][1] == 'E')
	{
		parse_we(map[i]);
		count++;
	}
	else if (map[i][0] == 'E' && map[i][1] == 'A')
	{
		parse_ea(map[i]);
		count++;
	}
	return (count);
}

int	texture_color(char **map, int i, int count)
{
	if (map[i][0] == 'F')
	{
		parse_f(map[i]);
		count++;
	}
	else if (map[i][0] == 'C')
	{
		parse_c(map[i]);
		count++;
	}
	return (count);
}

void	parse_textures(t_data *data)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (data->map_data[i][0])
	{
		count += texture_type(data->map_data, i, count);
		count += texture_color(data->map_data, i, count);
		i++;
	}
	if (count > 6)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

// FALTA COMPROBAR QUE EL MAPA ESTE LO ULTIMO DESPUES DE LOS DATOS