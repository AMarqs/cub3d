/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:57:52 by albmarqu          #+#    #+#             */
/*   Updated: 2025/07/31 13:44:27 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_color(char *map, t_game *game)
{
	if (map[0] == 'F')
	{
		parse_f((map + 1), game);
		game->data->count->count_f++;
	}
	else if (map[0] == 'C')
	{
		parse_c((map + 1), game);
		game->data->count->count_c++;
	}
}

int	is_direction(char *map)
{
	if ((map[0] == 'N' && map[1] == 'O') || (map[0] == 'S' && map[1] == 'O')
		|| (map[0] == 'W' && map[1] == 'E') || (map[0] == 'E' && map[1] == 'A'))
		return (1);
	return (0);
}

static void	process_info_line(t_game *game, int i)
{
	game->data->map_aux = ft_strtrim(game->data->map_data[i], " ");
	if (is_direction(game->data->map_aux))
		parse_texture(game->data->map_aux, game);
	else if (game->data->map_aux[0] == 'F' || game->data->map_aux[0] == 'C')
		parse_color(game->data->map_aux, game);
	else if (game->data->map_aux[0] != '\n')
	{
		free(game->data->map_aux);
		print_error("Wrong map info\n", game);
	}
	free(game->data->map_aux);
	game->data->map_aux = NULL;
	check_count(game->data->count, game);
}

void	parse_info(t_game *game)
{
	int	i;

	i = 0;
	game->data->count = calloc(1, sizeof(t_count));
	if (game->data->count == NULL)
		print_error("Error allocating memory\n", game);
	init_counters(game);
	while (game->data->map_data[i] && game->data->count->total != 6)
	{
		process_info_line(game, i);
		i++;
	}
	if (game->data->count->total != 6)
		print_error("Not enough texture data\n", game);
	parse_map(game, i);
}
