/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:29:35 by jortiz-m          #+#    #+#             */
/*   Updated: 2025/07/30 19:06:18 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_load_textures(t_game *game)
{
	ft_load_texture_north(game);
	ft_load_texture_east(game);
	ft_load_texture_south(game);
	ft_load_texture_west(game);
}

void	ft_load_texture_north(t_game *game)
{
	char			*path;
	mlx_texture_t	*texture;

	path = game->data->no_texture;
	texture = mlx_load_png(path);
	if (!texture)
	{
		free(path);
		ft_close_with_error(game);
		exit(EXIT_FAILURE);
	}
	game->images.no = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
}

void	ft_load_texture_south(t_game *game)
{
	char			*path;
	mlx_texture_t	*texture;

	path = game->data->so_texture;
	texture = mlx_load_png(path);
	if (!texture)
	{
		free(path);
		ft_close_with_error(game);
		exit(EXIT_FAILURE);
	}
	game->images.so = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
}

void	ft_load_texture_east(t_game *game)
{
	char			*path;
	mlx_texture_t	*texture;

	path = game->data->ea_texture;
	texture = mlx_load_png(path);
	if (!texture)
	{
		free(path);
		ft_close_with_error(game);
		exit(EXIT_FAILURE);
	}
	game->images.ea = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
}

void	ft_load_texture_west(t_game *game)
{
	char			*path;
	mlx_texture_t	*texture;

	path = game->data->we_texture;
	texture = mlx_load_png(path);
	if (!texture)
	{
		free(path);
		ft_close_with_error(game);
		exit(EXIT_FAILURE);
	}
	game->images.we = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
}
