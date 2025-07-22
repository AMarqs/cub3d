/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:29:44 by albmarqu          #+#    #+#             */
/*   Updated: 2025/07/22 15:03:11 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	file2map(int file, t_data *data)
{
	char	*line;
	int		i;

	line = get_next_line(file);
	i = 0;
	while (i < data->file_rows)
	{
		data->map_data[i] = line;
		line = get_next_line(file);
		i++;
	}
	data->map_data[data->file_rows] = NULL;
}

void	read_file(char *argv, t_data *data)
{
	int	file;

	file = open(argv, O_RDONLY);
	if (file == -1)
		print_error("Error opening file\n", data);
	data->map_data = malloc((data->file_rows + 1) * sizeof(char *));
	if (data->map_data == NULL)
	{
		close(file);
		print_error("Error allocating memory\n", data);
	}
	file2map(file, data);
	close(file);
}

void	open_file(char *argv, t_data *data)
{
	int		file;
	char	*line;

	file = open(argv, O_RDONLY);
	if (file == -1)
		print_error("Error opening file\n", data);
	data->file_rows = 0;
	line = get_next_line(file);
	while (line)
	{
		free(line);
		line = get_next_line(file);
		data->file_rows++;
	}
	free(line);
	close(file);
}

void	check_args(int argc, char **argv, t_data *data)
{
	if (argc != 2)
		print_error("Wrong number of arguments\n", data);
	if (ft_strncmp((argv[1] + ft_strlen(argv[1]) - 4), ".cub", 4))
		print_error("Bad extension\n", data);
}
