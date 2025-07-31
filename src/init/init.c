/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:30:09 by jortiz-m          #+#    #+#             */
/*   Updated: 2025/07/31 13:52:38 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_mlx(t_game	*game)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(WIDTH, HEIGHT, TITLE, true);
	if (!game->mlx)
		print_error("Could not init MLX42\n", game);
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img)
		print_error("Could not create image\n", game);
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
	game->player.move_speed = MOVE_SPEED;
	game->player.rot_speed = ROT_SPEED;
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
				ft_set_player_direction(game, col, row);
				return ;
			}
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
}
