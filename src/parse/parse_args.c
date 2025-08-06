/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:29:44 by albmarqu          #+#    #+#             */
/*   Updated: 2025/08/06 12:22:47 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	file2map(int file, t_game *game)
{
	char	*line;
	int		i;

	line = get_next_line(file);
	i = 0;
	while (i < game->data->file_rows)
	{
		game->data->map_data[i] = line;
		line = get_next_line(file);
		i++;
	}
	game->data->map_data[game->data->file_rows] = NULL;
}

void	read_file(char *argv, t_game *game)
{
	int	file;

	file = open(argv, O_RDONLY);
	if (file < 0)
		print_error("Error opening file\n", game);
	game->data->map_data = malloc((game->data->file_rows + 1) * sizeof(char *));
	if (game->data->map_data == NULL)
	{
		close(file);
		print_error("Error allocating memory\n", game);
	}
	file2map(file, game);
	close(file);
}

void	open_file(char *argv, t_game *game)
{
	int		file;
	char	*line;

	file = open(argv, O_RDONLY);
	if (file < 0)
		print_error("Error opening file\n", game);
	game->data->file_rows = 0;
	line = get_next_line(file);
	while (line)
	{
		free(line);
		line = get_next_line(file);
		game->data->file_rows++;
	}
	free(line);
	close(file);
}

void	check_args(int argc, char **argv, t_game *game)
{
	if (argc != 2)
		print_error("Wrong number of arguments\n", game);
	if (ft_strncmp((argv[1] + ft_strlen(argv[1]) - 4), ".cub", 4))
		print_error("Bad extension\n", game);
}
