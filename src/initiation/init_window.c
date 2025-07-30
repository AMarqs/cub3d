/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:33:25 by albmarqu          #+#    #+#             */
/*   Updated: 2025/07/29 18:45:02 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	display(t_game *game, mlx_image_t *image, int x, int y)
// {
// 	if (mlx_image_to_window(game->mlx, image, x, y) < 0)
// 	{
// 		write(2, "Error\nError displaying image\n", 29);
// 		free_image(game->image);
// 		f_close(game);
// 		exit(EXIT_FAILURE);
// 	}
// }

void	init_window(t_data *data, t_init *init)
{
	mlx_t			*mlx;
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	mlx = NULL;
	texture = NULL;
	img = NULL;
	// mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!mlx)
	{
		write(2, "Error\nError initializing mlx\n", 30);
		exit(EXIT_FAILURE);
	}
	init->mlx = mlx;
	init->img = malloc(sizeof(t_image));
	init->img->n_texture = mlx_load_png(data->no_texture);
	init->img->s_texture = mlx_load_png(data->so_texture);
	init->img->e_texture = mlx_load_png(data->we_texture);
	init->img->w_texture = mlx_load_png(data->ea_texture);
	if (!init->img->n_texture || !init->img->s_texture
		|| !init->img->e_texture || !init->img->w_texture)
	{
		write(2, "Error\nError loading texture\n", 28);
		exit(EXIT_FAILURE);
	}
	init->img->n_image = mlx_texture_to_image(mlx, init->img->n_texture);
	init->img->s_image = mlx_texture_to_image(mlx, init->img->s_texture);
	init->img->e_image = mlx_texture_to_image(mlx, init->img->e_texture);
	init->img->w_image = mlx_texture_to_image(mlx, init->img->w_texture);
	if (!init->img->n_image || !init->img->s_image
		|| !init->img->e_image || !init->img->w_image)
	{
		write(2, "Error\nError creating image\n", 27);
		exit(EXIT_FAILURE);
	}


	// if (mlx_image_to_window(mlx, img, 0, 0) < 0)
	// 	exit(EXIT_FAILURE);
	// mlx_loop(mlx);

	// mlx_delete_image(mlx, img);
	// mlx_delete_texture(texture);
	// mlx_terminate(mlx);
}
