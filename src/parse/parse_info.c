/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:57:52 by albmarqu          #+#    #+#             */
/*   Updated: 2025/07/21 17:24:14 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_counters(t_count *count)
{
	count->total = 0;
	count->count_no = 0;
	count->count_so = 0;
	count->count_we = 0;
	count->count_ea = 0;
	count->count_f = 0;
	count->count_c = 0;
}

void	check_count(t_count *count, t_data *data)
{
	if (count->count_no > 1 || count->count_so > 1 || count->count_we > 1
		|| count->count_ea > 1 || count->count_f > 1 || count->count_c > 1)
	{
		write(2, "Error\nWrong map information\n", 28);
		frees(data);
		exit(EXIT_FAILURE);
	}
	count->total = count->count_no + count->count_so + count->count_we
		+ count->count_ea + count->count_f + count->count_c;
}

void	parse_texture(char *map, t_data *data)
{
	if (map[0] == 'N' && map[1] == 'O')
	{
		parse_no(map, data);
		data->count->count_no++;
	}
	else if (map[0] == 'S' && map[1] == 'O')
	{
		parse_so(map, data);
		data->count->count_so++;
	}
	else if (map[0] == 'W' && map[1] == 'E')
	{
		parse_we(map, data);
		data->count->count_we++;
	}
	else if (map[0] == 'E' && map[1] == 'A')
	{
		parse_ea(map, data);
		data->count->count_ea++;
	}
}

void	parse_color(char *map, t_data *data)
{
	if (map[0] == 'F')
	{
		parse_f((map + 1), data);
		data->count->count_f++;
	}
	else if (map[0] == 'C')
	{
		parse_c((map + 1), data);
		data->count->count_c++;
	}
}

int	is_direction(char *map)
{
	if ((map[0] == 'N' && map[1] == 'O') || (map[0] == 'S' && map[1] == 'O')
		|| (map[0] == 'W' && map[1] == 'E') || (map[0] == 'E' && map[1] == 'A'))
		return (1);
	return (0);
}

void	parse_info(t_data *data)
{
	int		i;

	i = 0;
	data->count = malloc(sizeof(t_count));
	if (data->count == NULL)
		error_alocating(data);
	init_counters(data->count); ///////////////////////////////////// CON EL MEMSET ME HACE FALTA TAMBIEN INICIAR ESTO???
	while (data->map_data[i] && data->count->total != 6)
	{
		data->map_aux = ft_strtrim(data->map_data[i], " ");
		if (is_direction(data->map_aux))
			parse_texture(data->map_aux, data);
		else if (data->map_aux[0] == 'F' || data->map_aux[0] == 'C')
			parse_color(data->map_aux, data);
		else if (data->map_aux[0] != '\n')
		{
			write(2, "Error\nWrong map ubication\n", 26);
			frees(data);
			exit(EXIT_FAILURE);
		}
		check_count(data->count, data);
		i++;
	}
	if (data->count->total != 6)
	{
		write(2, "Error\nNot enough texture data\n", 30);
		frees(data);
		exit(EXIT_FAILURE);
	}
	parse_map(data, i);
}
