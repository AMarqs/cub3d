/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file2array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alba <alba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:30:49 by albmarqu          #+#    #+#             */
/*   Updated: 2025/07/09 13:12:47 by alba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	Voy leyendo el archivo y copiandolo linea por linea en la variable creada
*/
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

/*
	Abro el archivo y creo una variable donde almacenar la informacion
*/
void	read_file(char *argv, t_data *data)
{
	int	file;

	file = open(argv, O_RDONLY);
	if (file == -1)
	{
		write(2, "Error\nError opening file\n", 25);
		exit(EXIT_FAILURE);
	}
	data->map_data = malloc((data->file_rows + 1) * sizeof(char *));
	if (data->map_data == NULL)
	{
		close(file);
		write(2, "Error\nError allocating memory\n", 30);
		free(data->map_data);
		exit(EXIT_FAILURE);
	}
	file2map(file, data);
	close(file);
}

/*
	Abro el archivo y cuento el numero de lineas para luego reservar memoria
*/
void	open_file(char *argv, t_data *data)
{
	int		file;
	char	*line;

	file = open(argv, O_RDONLY);
	if (file == -1)
	{
		write(2, "Error\nError opening file\n", 25);
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
	close(file);
}