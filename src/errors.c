/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:52:39 by albmarqu          #+#    #+#             */
/*   Updated: 2025/08/06 12:26:11 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_freematrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		if (matrix[i] != NULL)
			free(matrix[i]);
		i++;
	}
	free(matrix);
	return (NULL);
}

void	free_data(t_data *data)
{
	if (data->no_texture)
		free(data->no_texture);
	if (data->so_texture)
		free(data->so_texture);
	if (data->ea_texture)
		free(data->ea_texture);
	if (data->we_texture)
		free(data->we_texture);
	if (data->f_rgb)
		free_matrix(data->f_rgb);
	if (data->c_rgb)
		free_matrix(data->c_rgb);
	if (data->floor)
		free(data->floor);
	if (data->ceiling)
		free(data->ceiling);
	if (data->map)
		ft_freematrix(data->map);
	if (data->count)
		free(data->count);
	if (data->map_data)
		ft_freematrix(data->map_data);
	free(data);
}

void	frees(t_game *game)
{
	if (game)
	{
		if (game->data)
			free_data(game->data);
		if (game->images.no)
			mlx_delete_image(game->mlx, game->images.no);
		if (game->images.so)
			mlx_delete_image(game->mlx, game->images.so);
		if (game->images.ea)
			mlx_delete_image(game->mlx, game->images.ea);
		if (game->images.we)
			mlx_delete_image(game->mlx, game->images.we);
		if (game->img)
			mlx_delete_image(game->mlx, game->img);
		if (game->mlx)
			mlx_terminate(game->mlx);
		free(game);
	}
}

void	print_error(char *str, t_game *game)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	frees(game);
	exit(EXIT_FAILURE);
}
