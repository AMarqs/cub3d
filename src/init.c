
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

void	ft_init_mlx(t_game *game)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(WIDTH, HEIGHT, TITLE, true);
	if (!game->mlx)
	{
		fprintf(stderr, "Error:\nCould not init MLX42");
		ft_bad_close(game);
	}
	game->textures = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->textures)
	{
		fprintf(stderr, "Error:\nCould not create image");
		ft_bad_close(game);
	}
	mlx_image_to_window(game->mlx, game->textures 0, 0);
}

void	ft_init_game(t_game *game)
{
	ft_init_mlx(game);
}

