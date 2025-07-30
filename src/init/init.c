/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:30:09 by jortiz-m          #+#    #+#             */
/*   Updated: 2025/07/30 19:07:57 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_mlx(t_game	*game)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(WIDTH, HEIGHT, TITLE, true);
	if (!game->mlx)
	{
		print_error("Could not init MLX42\n", game);
		ft_close_with_error(game);
	}
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img)
	{
		print_error("Could not create image\n", game);
		ft_close_with_error(game);
	}
	mlx_image_to_window(game->mlx, game->img, 0, 0);
}

void	ft_set_player_plane(t_game *game, int x, int y)
{
	if (game->data->map[y][x] == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = 0.66;
	}
	else if (game->data->map[y][x] == 'W')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = -0.66;
	}
}

void	ft_set_player_direction(t_game *game, int x, int y)
{
	game->player.x = (double)x + 0.5;
	game->player.y = (double)y + 0.5;
	if (game->data->map[y][x] == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
		game->player.plane_x = 0.66;
		game->player.plane_y = 0;
	}
	else if (game->data->map[y][x] == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
		game->player.plane_x = -0.66;
		game->player.plane_y = 0;
	}
	ft_set_player_plane(game, x, y);
	game->player.move_speed = 0.05;
	game->player.rot_speed = 0.17;
}

void	ft_init_player_position(t_game *game)
{
	int		row;
	int		col;
	char	box;

	row = 0;
	box = 0;
	while (game->data->map[row])
	{
		col = 0;
		while (game->data->map[row][col])
		{
			box = game->data->map[row][col];
			if (box == 'N' || box == 'S' || box == 'E' || box == 'W')
			{
				game->player.y = row;
				game->player.x = col;
			}
			if (box == 'N')
				game->player.dir = 1;
			else if (box == 'S')
				game->player.dir = 2;
			else if (box == 'E')
				game->player.dir = 3;
			else if (box == 'W')
				game->player.dir = 4;
			col++;
		}
		row++;
	}
}

void	ft_init(t_game *game)
{
	ft_init_mlx(game);
	ft_load_textures(game);
	ft_init_player_position(game);
	mlx_loop_hook(game->mlx, &ft_update_game, game);
	mlx_key_hook(game->mlx, &key_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}
