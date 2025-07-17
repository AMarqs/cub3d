/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:57:52 by albmarqu          #+#    #+#             */
/*   Updated: 2025/07/17 21:45:23 by albmarqu         ###   ########.fr       */
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

void	check_count(t_count *count)
{
	if (count->count_no > 1 || count->count_so > 1 || count->count_we > 1
		|| count->count_ea > 1 || count->count_f > 1 || count->count_c > 1)
	{
		write(2, "Error\nWrong map information\n", 28);
		exit(EXIT_FAILURE);
	}
	count->total = count->count_no + count->count_so + count->count_we
		+ count->count_ea + count->count_f + count->count_c;
}

void	texture_type(t_data *data, int i, t_count *count)
{
	char	**map;

	map = data->map_data;
	if (map[i][0] == 'N' && map[i][1] == 'O')
	{
		parse_no(map[i], data);
		count->count_no++;
	}
	else if (map[i][0] == 'S' && map[i][1] == 'O')
	{
		parse_so(map[i], data);
		count->count_so++;
	}
	else if (map[i][0] == 'W' && map[i][1] == 'E')
	{
		parse_we(map[i], data);
		count->count_we++;
	}
	else if (map[i][0] == 'E' && map[i][1] == 'A')
	{
		parse_ea(map[i], data);
		count->count_ea++;
	}
}

void	texture_color(t_data *data, int i, t_count *count)
{
	char	**map;

	map = data->map_data;
	if (map[i][0] == 'F')
	{
		parse_f((map[i] + 1), data);
		count->count_f++;
	}
	else if (map[i][0] == 'C')
	{
		parse_c((map[i] + 1), data);
		count->count_c++;
	}
}

void	parse_info(t_data *data)
{
	int			i;
	t_count		*count;

	i = 0;
	count = malloc(sizeof(t_count));
	if (count == NULL)
	{
		free(count);
		error_alocating(data);
	}
	init_counters(count);
	while (data->map_data[i] && count->total != 6)
	{
		data->map_data[i] = ft_strtrim(data->map_data[i], " ");
		texture_type(data, i, count);
		texture_color(data, i, count);
		check_count(count);
		i++;
	}
	if (count->total != 6)
	{
		write(2, "Error\nNot enough texture data\n", 30);
		exit(EXIT_FAILURE);
	}
	parse_map(data, i);
}
