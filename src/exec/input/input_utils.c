/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:28:52 by jortiz-m          #+#    #+#             */
/*   Updated: 2025/07/31 11:53:29 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_rotate_player(t_player *p, double dir)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = p->dir_x;
	old_plane_x = p->plane_x;
	p->dir_x = p->dir_x * cos(dir) - p->dir_y * sin(dir);
	p->dir_y = old_dir_x * sin(dir) + p->dir_y * cos(dir);
	p->plane_x = p->plane_x * cos(dir) - p->plane_y * sin(dir);
	p->plane_y = old_plane_x * sin(dir) + p->plane_y * cos(dir);
}

int	ft_is_wall(t_game *game, double x, double y)
{
	int	map_x;
	int	map_y;

	if (x < 0 || y < 0)
		return (1);
	map_x = (int)x;
	map_y = (int)y;
	if (!game->data->map[map_y] || !game->data->map[map_y][map_x])
		return (1);
	if (game->data->map[map_y][map_x] == '1')
		return (1);
	return (0);
}
