/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:00:00 by jortiz-m          #+#    #+#             */
/*   Updated: 2025/07/16 12:18:07 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Temporary simple rendering function
void	render_frame(t_game *game)
{
	int	x, y;
	int	color;

	// Clear screen with floor/ceiling colors
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT / 2)
				color = create_rgb(game->data.ceiling.r,
					game->data.ceiling.g, game->data.ceiling.b);
			else
				color = create_rgb(game->data.floor.r,
					game->data.floor.g, game->data.floor.b);
			my_mlx_pixel_put(&game->screen, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->screen.img, 0, 0);
}

// Temporary raycast function (to be implemented properly later)
void	raycast(t_game *game)
{
	// For now, just render basic frame
	render_frame(game);
}

int	game_loop(t_game *game)
{
	raycast(game);
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == 65307) // ESC key
		close_win(game);
	// Add movement keys later (W, A, S, D, arrows)
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	(void)keycode;
	(void)game;
	return (0);
}

void	load_textures(t_game *game)
{
	// Load texture files into t_img structures
	// This will be implemented when texture loading is needed
	(void)game;
}
