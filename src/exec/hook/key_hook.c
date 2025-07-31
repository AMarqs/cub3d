/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:28:08 by jortiz-m          #+#    #+#             */
/*   Updated: 2025/07/31 13:31:31 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_W)
		game->control.w = (keydata.action != MLX_RELEASE);
	if (keydata.key == MLX_KEY_S)
		game->control.s = (keydata.action != MLX_RELEASE);
	if (keydata.key == MLX_KEY_A)
		game->control.a = (keydata.action != MLX_RELEASE);
	if (keydata.key == MLX_KEY_D)
		game->control.d = (keydata.action != MLX_RELEASE);
	if (keydata.key == MLX_KEY_LEFT)
		game->control.left = (keydata.action != MLX_RELEASE);
	if (keydata.key == MLX_KEY_RIGHT)
		game->control.right = (keydata.action != MLX_RELEASE);
	if (keydata.key == MLX_KEY_KP_ADD && keydata.action == MLX_PRESS)
		game->player.move_speed += 0.01;
	if (keydata.key == MLX_KEY_KP_SUBTRACT && keydata.action == MLX_PRESS)
		game->player.move_speed = fmax(0.01, game->player.move_speed - 0.01);
}
