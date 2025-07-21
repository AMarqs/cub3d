/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:22:48 by albmarqu          #+#    #+#             */
/*   Updated: 2025/07/21 17:22:04 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

long	ft_atol(const char *str)
{
	long	i;
	long	sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - 48;
		i++;
	}
	num = num * sign;
	return (num);
}

long	color_range(const char *str, t_data *data)
{
	long	num;

	if (ft_strlen(str) > 11)
	{
		write(2, "Error\nInvaild RGB color\n", 24);
		frees(data);
		exit(EXIT_FAILURE);
	}
	num = ft_atol(str);
	if (num < 0 || num > 255)
	{
		write(2, "Error\nInvaild RGB color\n", 24);
		frees(data);
		exit(EXIT_FAILURE);
	}
	return (num);
}

void	count_commas(char *str, t_data *data)
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
		write(2, "Error\nWrong RGB color format\n", 29);
		frees(data);
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
	count_commas(f, data);
	floor = ft_split(f, ',');
	data->floor->r = color_range(floor[0], data);
	data->floor->g = color_range(floor[1], data);
	data->floor->b = color_range(floor[2], data);
}

void	parse_c(char *c, t_data *data)
{
	char	**ceiling;

	data->ceiling = malloc(sizeof(t_color));
	if (data->ceiling == NULL)
		error_alocating(data);
	c = ft_strtrim(c, " ");
	count_commas(c, data);
	ceiling = ft_split(c, ',');
	data->ceiling->r = color_range(ceiling[0], data);
	data->ceiling->g = color_range(ceiling[1], data);
	data->ceiling->b = color_range(ceiling[2], data);
}
