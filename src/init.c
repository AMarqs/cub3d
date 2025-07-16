
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:00:00 by jortiz-m          #+#    #+#             */
/*   Updated: 2025/07/16 11:00:00 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_win(t_game *game)
{
	if (game->screen.img)
		mlx_destroy_image(game->mlx, game->screen.img);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
	return (0);
}

void	init_mlx_image(t_game *game)
{
	game->screen.img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->screen.img)
		error_exit("Error creating MLX image");
	game->screen.addr = mlx_get_data_addr(game->screen.img,
		&game->screen.bits_per_pixel,
		&game->screen.line_length,
		&game->screen.endian);
	game->screen.width = WIN_WIDTH;
	game->screen.height = WIN_HEIGHT;
}

void	init_player(t_game *game, char direction, int x, int y)
{
	game->player.x = (double)x + 0.5;
	game->player.y = (double)y + 0.5;
	
	if (direction == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
		game->player.plane_x = 0.66;
		game->player.plane_y = 0;
	}
	else if (direction == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
		game->player.plane_x = -0.66;
		game->player.plane_y = 0;
	}
	else if (direction == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = 0.66;
	}
	else if (direction == 'W')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = -0.66;
	}
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit("Error initializing MLX");
	game->window = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	if (!game->window)
		error_exit("Error creating window");
	init_mlx_image(game);
	mlx_hook(game->window, 17, 0, close_win, game);
	mlx_hook(game->window, 2, 1L << 0, handle_key_press, game);
	mlx_hook(game->window, 3, 1L << 1, handle_key_release, game);
	mlx_loop_hook(game->mlx, game_loop, game);
}
