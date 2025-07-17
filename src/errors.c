/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:52:39 by albmarqu          #+#    #+#             */
/*   Updated: 2025/07/17 21:44:46 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	frees(t_data *data)
{
	if (data->map_data)
		free(data->map_data);
	if (data->floor)
		free(data->floor);
	if (data->ceiling)
		free(data->ceiling);
	if (data->map)
		free(data->map);
	if (data)
		free(data);
}

void	error_alocating(t_data *data)
{
	write(2, "Error\nError allocating memory\n", 30);
	frees(data);
	exit(EXIT_FAILURE);
}
