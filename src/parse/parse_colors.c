/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:22:48 by albmarqu          #+#    #+#             */
/*   Updated: 2025/07/30 18:26:50 by albmarqu         ###   ########.fr       */
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

long	color_range(const char *str, t_game *game)
{
	long	num;

	if (ft_strlen(str) > 11)
		print_error("Invaild RGB color\n", game);
	num = ft_atol(str);
	if (num < 0 || num > 255)
		print_error("Invaild RGB color\n", game);
	return (num);
}

void	count_commas(char *str, t_game *game)
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
		print_error("Wrong RGB color format\n", game);
}

void	parse_f(char *f, t_game *game)
{
	char	**floor;
	char	*f_trimmed;
	int		i;

	game->data->floor = calloc(1, sizeof(t_color));
	if (game->data->floor == NULL)
		print_error("Error allocating memory\n", game);
	f_trimmed = ft_strtrim(f, " ");
	count_commas(f_trimmed, game);
	floor = ft_split(f_trimmed, ',');
	game->data->floor->r = color_range(floor[0], game);
	game->data->floor->g = color_range(floor[1], game);
	game->data->floor->b = color_range(floor[2], game);
	i = 0;
	while (floor[i])
		free(floor[i++]);
	free(floor);
	free(f_trimmed);
}

void	parse_c(char *c, t_game *game)
{
	char	**ceiling;
	char	*c_trimmed;
	int		i;

	game->data->ceiling = calloc(1, sizeof(t_color));
	if (game->data->ceiling == NULL)
		print_error("Error allocating memory\n", game);
	c_trimmed = ft_strtrim(c, " ");
	count_commas(c_trimmed, game);
	ceiling = ft_split(c_trimmed, ',');
	game->data->ceiling->r = color_range(ceiling[0], game);
	game->data->ceiling->g = color_range(ceiling[1], game);
	game->data->ceiling->b = color_range(ceiling[2], game);
	i = 0;
	while (ceiling[i])
		free(ceiling[i++]);
	free(ceiling);
	free(c_trimmed);
}
