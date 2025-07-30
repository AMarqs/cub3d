/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:28:52 by jortiz-m          #+#    #+#             */
/*   Updated: 2025/07/30 11:30:35 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_rotate_player(t_player *p, double dir)
{
	double	old_dir_x;
	double	old_plane_x;
	double	angle;

	old_dir_x = p->dir_x;
	old_plane_x = p->plane_x;
	angle = dir * p->rot_speed;
	p->dir_x = p->dir_x * cos(angle) - p->dir_y * sin(angle);
	p->dir_y = old_dir_x * sin(angle) + p->dir_y * cos(angle);
	p->plane_x = p->plane_x * cos(angle) - p->plane_y * sin(angle);
	p->plane_y = old_plane_x * sin(angle) + p->plane_y * cos(angle);
}

int	ft_is_wall(t_game *game, double x, double y)
{
	return (
		game->map[(int)(y)][(int)(x)] == '1' ||
		game->map[(int)(y + COLLISION_MARGIN)][(int)(x)] == '1' ||
		game->map[(int)(y - COLLISION_MARGIN)][(int)(x)] == '1' ||
		game->map[(int)(y)][(int)(x + COLLISION_MARGIN)] == '1' ||
		game->map[(int)(y)][(int)(x - COLLISION_MARGIN)] == '1' ||
		game->map[(int)(y + COLLISION_MARGIN)]
			[(int)(x + COLLISION_MARGIN)] == '1' ||
		game->map[(int)(y - COLLISION_MARGIN)]
			[(int)(x - COLLISION_MARGIN)] == '1'
	);
}
