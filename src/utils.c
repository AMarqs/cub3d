/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:00:00 by jortiz-m          #+#    #+#             */
/*   Updated: 2025/07/16 12:03:21 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_exit(char *message)
{
	write(2, "Error\n", 6);
	if (message)
	{
		write(2, message, ft_strlen(message));
		write(2, "\n", 1);
	}
	exit(EXIT_FAILURE);
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < img->width && y >= 0 && y < img->height)
	{
		dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

int	get_texture_color(t_img *texture, int x, int y)
{
	char	*dst;

	if (x >= 0 && x < texture->width && y >= 0 && y < texture->height)
	{
		dst = texture->addr + (y * texture->line_length + x * (texture->bits_per_pixel / 8));
		return (*(unsigned int*)dst);
	}
	return (0);
}

void	free_game(t_game *game)
{
	int	i;

	if (game->map.grid)
	{
		i = 0;
		while (i < game->map.height)
		{
			free(game->map.grid[i]);
			i++;
		}
		free(game->map.grid);
	}
	if (game->data.no_texture)
		free(game->data.no_texture);
	if (game->data.so_texture)
		free(game->data.so_texture);
	if (game->data.ea_texture)
		free(game->data.ea_texture);
	if (game->data.we_texture)
		free(game->data.we_texture);
	if (game->data.map_data)
	{
		i = 0;
		while (i < game->data.file_rows)
		{
			free(game->data.map_data[i]);
			i++;
		}
		free(game->data.map_data);
	}
}
