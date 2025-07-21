/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:52:39 by albmarqu          #+#    #+#             */
/*   Updated: 2025/07/21 17:25:12 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	frees(t_data *data)
{
	if (data->no_texture)
		free(data->no_texture);
	if (data->so_texture)
		free(data->so_texture);
	if (data->we_texture)
		free(data->we_texture);
	if (data->ea_texture)
		free(data->ea_texture);
	if (data->floor)
		free(data->floor);
	if (data->ceiling)
		free(data->ceiling);
	if (data->map)
		ft_freematrix(data->map);
	if (data->count)
		free(data->count);
	if (data->map_aux)
		free(data->map_aux);
	if (data->map_data)
		ft_freematrix(data->map_data);
	if (data)
		free(data);
}

void	error_alocating(t_data *data)
{
	write(2, "Error\nError allocating memory\n", 30);
	frees(data);
	exit(EXIT_FAILURE);
}
