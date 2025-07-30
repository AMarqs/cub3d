/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_counter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:55:47 by albmarqu          #+#    #+#             */
/*   Updated: 2025/07/30 18:28:31 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_counters(t_game *game)
{
	game->data->count->total = 0;
	game->data->count->count_no = 0;
	game->data->count->count_so = 0;
	game->data->count->count_we = 0;
	game->data->count->count_ea = 0;
	game->data->count->count_f = 0;
	game->data->count->count_c = 0;
}

void	check_count(t_count *count, t_game *game)
{
	if (count->count_no > 1 || count->count_so > 1 || count->count_we > 1
		|| count->count_ea > 1 || count->count_f > 1 || count->count_c > 1)
		print_error("Wrong map information\n", game);
	count->total = count->count_no + count->count_so + count->count_we
		+ count->count_ea + count->count_f + count->count_c;
}
