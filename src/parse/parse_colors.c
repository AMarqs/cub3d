/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:22:48 by albmarqu          #+#    #+#             */
/*   Updated: 2025/08/06 17:12:04 by albmarqu         ###   ########.fr       */
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
	int		i;

	i = 0;
	if (str == NULL)
		print_error("Not enough RGB color components\n", game);
	if (ft_strlen(str) > 11)
		print_error("Invalid RGB color\n", game);
	while (str[i] && str[i] != '\n')
	{
		if (!ft_isdigit(str[i]))
			print_error("Invalid RGB color\n", game);
		i++;
	}
	num = ft_atol(str);
	if (num < 0 || num > 255)
		print_error("Invalid RGB color\n", game);
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
	{
		free(str);
		print_error("Wrong RGB color format\n", game);
	}
}

void	parse_f(char *f, t_game *game)
{
	char	*f_trimmed;

	game->data->floor = calloc(1, sizeof(t_color));
	if (game->data->floor == NULL)
	{
		free(f);
		print_error("Error allocating memory\n", game);
	}
	f_trimmed = ft_strtrim((f + 1), " ");
	count_commas(f_trimmed, game);
	game->data->f_rgb = ft_split(f_trimmed, ',');
	free(f_trimmed);
	if (game->data->f_rgb[0] == NULL || game->data->f_rgb[1] == NULL
		|| game->data->f_rgb[2] == NULL)
		print_error("Not enough RGB color components\n", game);
	if (game->data->f_rgb[2][0] == '\n')
		game->data->f_rgb[2] = NULL;
	game->data->floor->r = color_range(game->data->f_rgb[0], game);
	game->data->floor->g = color_range(game->data->f_rgb[1], game);
	game->data->floor->b = color_range(game->data->f_rgb[2], game);
}

void	parse_c(char *c, t_game *game)
{
	char	*c_trimmed;

	game->data->ceiling = calloc(1, sizeof(t_color));
	if (game->data->ceiling == NULL)
	{
		free(c);
		print_error("Error allocating memory\n", game);
	}
	c_trimmed = ft_strtrim((c + 1), " ");
	count_commas(c_trimmed, game);
	game->data->c_rgb = ft_split(c_trimmed, ',');
	free(c_trimmed);
	if (game->data->c_rgb[0] == NULL || game->data->c_rgb[1] == NULL
		|| game->data->c_rgb[2] == NULL)
		print_error("Not enough RGB color components\n", game);
	if (game->data->c_rgb[2][0] == '\n')
		game->data->c_rgb[2] = NULL;
	game->data->ceiling->r = color_range(game->data->c_rgb[0], game);
	game->data->ceiling->g = color_range(game->data->c_rgb[1], game);
	game->data->ceiling->b = color_range(game->data->c_rgb[2], game);
}
