/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:57:52 by albmarqu          #+#    #+#             */
/*   Updated: 2025/07/10 19:15:18 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	texture_type(t_data *data, char **map, int i, int count)
{
	if (map[i][0] == 'N' && map[i][1] == 'O')
	{
		parse_no(map[i], data);
		count++;
	}
	else if (map[i][0] == 'S' && map[i][1] == 'O')
	{
		parse_so(map[i], data);
		count++;
	}
	else if (map[i][0] == 'W' && map[i][1] == 'E')
	{
		parse_we(map[i], data);
		count++;
	}
	else if (map[i][0] == 'E' && map[i][1] == 'A')
	{
		parse_ea(map[i], data);
		count++;
	}
	return (count);
}

// int	texture_color(char **map, int i, int count)
// {
// 	if (map[i][0] == 'F')
// 	{
// 		parse_f(map[i]);
// 		count++;
// 	}
// 	else if (map[i][0] == 'C')
// 	{
// 		parse_c(map[i]);
// 		count++;
// 	}
// 	return (count);
// }

void	parse_textures(t_data *data)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (data->map_data[i][0])
	{
		count += texture_type(data, data->map_data, i, count);
		// count += texture_color(data, data->map_data, i, count);
		i++;
	}
	if (count != 6)
	{
		write(2, "Error\nNot enough texture data\n", 30);
		exit(EXIT_FAILURE);
	}
}

// FALTA COMPROBAR QUE EL MAPA ESTE LO ULTIMO DESPUES DE LOS DATOS