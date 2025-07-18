/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:22:48 by albmarqu          #+#    #+#             */
/*   Updated: 2025/07/18 13:45:20 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	count_commas(char *str)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (str[i] != '\n')
	{
		if (str[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2)
	{
		write(2, "Error\nWrong color format\n", 25);
		exit(EXIT_FAILURE);
	}
}

void	color_range(int i)
{
	if (i < 0 || i > 255)
	{
		write(2, "Error\nWrong color range\n", 24);
		exit(EXIT_FAILURE);
	}
}

void	parse_f(char *f, t_data *data)
{
	char	**floor;

	data->floor = malloc(sizeof(t_color));
	if (data->floor == NULL)
		error_alocating(data);
	f = ft_strtrim(f, " ");
	count_commas(f);
	floor = ft_split(f, ',');
	/// CALCULAR LONGITUD DEL STRING, SI ES MAYOR QUE 13 ESTÁ MAL PORQUE TE PASAS DE NUMERO
	data->floor->r = ft_atoi(floor[0]);
	data->floor->g = ft_atoi(floor[1]);
	data->floor->b = ft_atoi(floor[2]);
	color_range(data->floor->r);
	color_range(data->floor->g);
	color_range(data->floor->b);
}

void	parse_c(char *c, t_data *data)
{
	char	**ceiling;

	data->ceiling = malloc(sizeof(t_color));
	if (data->ceiling == NULL)
		error_alocating(data);
	c = ft_strtrim(c, " ");
	count_commas(c);
	ceiling = ft_split(c, ',');
	//////////////////
	data->ceiling->r = ft_atoi(ceiling[0]);
	data->ceiling->g = ft_atoi(ceiling[1]);
	data->ceiling->b = ft_atoi(ceiling[2]);
	color_range(data->ceiling->r);
	color_range(data->ceiling->g);
	color_range(data->ceiling->b);
}
