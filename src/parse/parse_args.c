/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:29:44 by albmarqu          #+#    #+#             */
/*   Updated: 2025/07/17 21:49:13 by albmarqu         ###   ########.fr       */
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
		error_alocating(data);
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

/*
	1. Compruebo si el numero de argumentos es 2: el nombre del programa en si
	   y el nombre del archivo para el mapa.
	2. Compruebo si el archivo del mapa tiene como extensión .cub
*/
void	check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		write(2, "Error\nWrong number of arguments\n", 32);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp((argv[1] + ft_strlen(argv[1]) - 4), ".cub", 4))
	{
		write(2, "Error\nBad extension\n", 20);
		exit(EXIT_FAILURE);
	}
}
