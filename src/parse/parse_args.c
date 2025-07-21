/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:29:44 by albmarqu          #+#    #+#             */
/*   Updated: 2025/07/21 17:17:24 by albmarqu         ###   ########.fr       */
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
	{
		write(2, "Error\nError opening file\n", 25);
		frees(data);
		exit(EXIT_FAILURE);
	}
	data->map_data = malloc((data->file_rows + 1) * sizeof(char *));
	if (data->map_data == NULL)
	{
		close(file);
		error_alocating(data);
	}
	file2map(file, data);
	close(file);
}

void	check_args(int argc, char **argv, t_data *data)
{
	if (argc != 2)
	{
		write(2, "Error\nWrong number of arguments\n", 32);
		free(data);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp((argv[1] + ft_strlen(argv[1]) - 4), ".cub", 4))
	{
		write(2, "Error\nBad extension\n", 20);
		free(data);
		exit(EXIT_FAILURE);
	}
}
