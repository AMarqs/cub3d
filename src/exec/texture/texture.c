/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:29:35 by jortiz-m          #+#    #+#             */
/*   Updated: 2025/07/31 13:21:31 by jortiz-m         ###   ########.fr       */
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
		print_error("Could not init MLX42\n", game);
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
		print_error("Could not init MLX42\n", game);
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
		print_error("Could not init MLX42\n", game);
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
		print_error("Could not init MLX42\n", game);
	game->images.we = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
}
