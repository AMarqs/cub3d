/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:45:21 by albmarqu          #+#    #+#             */
/*   Updated: 2025/07/21 17:16:56 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	open_file(char *argv, t_data *data)
{
	int		file;
	char	*line;

	file = open(argv, O_RDONLY);
	if (file == -1)
	{
		write(2, "Error\nError opening file\n", 25);
		free(data);
		exit(EXIT_FAILURE);
	}
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

void	open_texture_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nNo such file or directory: ", 32);
		write(2, path, ft_strlen(path));
		write(2, "\n", 1);
		exit(EXIT_FAILURE);
	}
	close(fd);
}
