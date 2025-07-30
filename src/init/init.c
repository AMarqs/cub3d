/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:30:09 by jortiz-m          #+#    #+#             */
/*   Updated: 2025/07/30 11:30:31 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_mlx(t_game	*game)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(WIDTH, HEIGHT, TITLE, true);
	if (!game->mlx)
	{
		fprintf(stderr, "Error:\nCould not init MLX42");
		ft_close_with_error(game);
	}
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img)
	{
		fprintf(stderr, "Error:\nCould not create image");
		ft_close_with_error(game);
	}
	mlx_image_to_window(game->mlx, game->img, 0, 0);
}

void	ft_set_player_plane(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = 0.66;
	}
	else if (game->map[y][x] == 'W')
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
	if (game->map[y][x] == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
		game->player.plane_x = 0.66;
		game->player.plane_y = 0;
	}
	else if (game->map[y][x] == 'S')
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
	int	x;
	int	y;

	y = 0;
	while (game->map[y] && (game->map[y][0] == 'N' || game->map[y][0] == 'S'
		|| game->map[y][0] == 'E' || game->map[y][0] == 'W'
		|| game->map[y][0] == 'F' || game->map[y][0] == 'C'
		|| game->map[y][0] == '\n'))
		y++;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'N' || game->map[y][x] == 'S'
				|| game->map[y][x] == 'E' || game->map[y][x] == 'W')
			{
				ft_set_player_direction(game, x, y);
				return ;
			}
			x++;
		}
		y++;
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
