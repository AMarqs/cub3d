/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:29:23 by jortiz-m          #+#    #+#             */
/*   Updated: 2025/07/31 11:15:53 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_background(t_game *game)
{
	uint32_t	c_color;
	uint32_t	f_color;
	int			x;
	int			y;

	c_color = (game->data->ceiling->r << 24) | (game->data->ceiling->g << 16)
		| (game->data->ceiling->b << 8) | 255;
	f_color = (game->data->floor->r << 24) | (game->data->floor->g << 16)
		| (game->data->floor->b << 8) | 255;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				mlx_put_pixel(game->img, x, y, c_color);
			else
				mlx_put_pixel(game->img, x, y, f_color);
			x++;
		}
		y++;
	}
}

void	ft_draw_vertical_line(mlx_image_t *img, t_line line)
{
	int	y;

	if (!img)
		return ;
	y = line.y_start;
	while (y <= line.y_end)
	{
		if (y >= 0 && y < (int)img->height && line.x >= 0
			&& line.x < (int)img->width)
			mlx_put_pixel(img, line.x, y, line.color);
		y++;
	}
}

void	ft_draw_column(t_game *game, int x, int start, int end)
{
	t_line	line;

	line.x = x;
	line.y_start = start;
	line.y_end = end;
	line.color = 0xFFFFFFFF;
	ft_draw_vertical_line(game->img, line);
}

void	ft_update_game(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	ft_handle_input(game);
	ft_draw_background(game);
	ft_raycast_all_columns(game);
}
