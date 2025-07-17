/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:22:48 by albmarqu          #+#    #+#             */
/*   Updated: 2025/07/17 18:44:04 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	color_range(int i)
{
	if (i < 0 || i > 255)
	{
		write(2, "Error\nWrong color range\n", 24);
		return (EXIT_FAILURE);
	}
}

void	parse_f(char *f, t_data *data)
{
	char	**floor;

	f = ft_strtrim(f, " ");
	floor = ft_split(f, ",");
	data->floor.r = ft_atoi(floor[1]);
	data->floor.g = ft_atoi(floor[2]);
	data->floor.b = ft_atoi(floor[3]);
	color_range(data->floor.r);
	color_range(data->floor.g);
	color_range(data->floor.b);
}

void	parse_c(char *c, t_data *data)
{
	char	**ceiling;

	c = ft_strtrim(c, " ");
	ceiling = ft_split(c, ",");
	data->ceiling.r = ft_atoi(ceiling[1]);
	data->ceiling.g = ft_atoi(ceiling[2]);
	data->ceiling.b = ft_atoi(ceiling[3]);
	color_range(data->ceiling.r);
	color_range(data->ceiling.g);
	color_range(data->ceiling.b);
}
