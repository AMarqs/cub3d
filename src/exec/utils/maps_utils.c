/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:29:42 by jortiz-m          #+#    #+#             */
/*   Updated: 2025/07/30 12:21:06 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_count_lines(char *map, t_game *game)
{
	char	*line;
	int		len;
	int		fd;
	int		map_started;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error\nCould not open the file to count lines.\n");
		ft_close_with_error(game);
	}
	line = get_next_line(fd);
	len = 0;
	map_started = 0;
	while (line)
	{
		// Buscar el inicio del mapa
		if (!map_started)
		{
			int j = 0;
			while (line[j] && (line[j] == ' ' || line[j] == '\t'))
				j++;
			if (line[j] == '1')
				map_started = 1;
		}
		// Solo contar líneas del mapa
		if (map_started)
			len++;	
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	game->height = len;
	return (len);
}

void	ft_free_map(t_game *game)
{
	int	i;

	i = -1;
	if (!game)
		return ;
	if (game->map)
	{
		while (++i < game->height && game->map[i])
			free(game->map[i]);
		free(game->map);
		game->map = NULL;
	}
	if (game->filename)
	{
		free(game->filename);
		game->filename = NULL;
	}
}

void	ft_read_map_lines(int fd, char *line, t_game *game)
{
	int		i;
	int		map_started;

	i = 0;
	map_started = 0;
	while (line)
	{
		// Buscar el inicio del mapa (primera línea que contiene '1' o espacios seguidos de '1')
		if (!map_started)
		{
			int j = 0;
			while (line[j] && (line[j] == ' ' || line[j] == '\t'))
				j++;
			if (line[j] == '1')
				map_started = 1;
		}
		// Si ya empezó el mapa, procesar la línea
		if (map_started)
		{
			if (line[0] == '\n')
				game->map[i] = ft_strdup("\n");
			else if (line[ft_strlen(line) - 1] == '\n' )
				game->map[i] = ft_substr(line, 0, ft_strlen(line) - 1);
			else
				game->map[i] = ft_strdup(line);
			if (!game->map[i])
			{
				fprintf(stderr, "Error\nCould not duplicate line.\n");
				free(line);
				ft_close_with_error(game);
			}
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	game->map[i] = NULL;
}

void	ft_read_map(t_game *game, char **argv)
{
	char	*line;
	int		fd;

	// Guardar el filename para usar en la carga de texturas
	game->filename = ft_strdup(argv[1]);
	
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error\nCould not open the file properly.\n");
		exit(EXIT_FAILURE);
	}
	game->map = malloc(sizeof(char *) * (ft_count_lines(argv[1], game) + 1));
	if (!game->map)
	{
		fprintf(stderr, "Error\nCould not allocate memory for the grid.\n");
		ft_close_with_error(game);
	}
	line = get_next_line(fd);
	if (!line)
	{
		fprintf(stderr, "Error\nThe map is empty\n");
		ft_close_with_error(game);
	}
	ft_read_map_lines(fd, line, game);
	close(fd);
	
	// Validar que el mapa esté cerrado por paredes
	ft_validate_map_walls(game);
}

void	ft_check_name(char **argv)
{
	int	len;

	len = ft_strlen(argv[1]);
	if (argv[1][len - 1] != 'b' || argv[1][len - 2] != 'u'
		|| argv[1][len - 3] != 'c' || argv[1][len - 4] != '.')
	{
		fprintf(stderr, "Error\nThe map must end with .cub.\n");
		exit(EXIT_FAILURE);
	}
}

void	ft_validate_map_walls(t_game *game)
{
	int	row;
	int	col;
	int	map_height;
	int	line_len;

	// Contar filas del mapa
	map_height = 0;
	while (game->map[map_height])
		map_height++;

	row = 0;
	while (game->map[row])
	{
		col = 0;
		line_len = ft_strlen(game->map[row]);
		if (line_len > 0 && game->map[row][line_len - 1] == '\n')
			line_len--;
			
		while (col < line_len)
		{
			// Si encontramos un espacio transitable
			if (game->map[row][col] == '0' || game->map[row][col] == 'N' 
				|| game->map[row][col] == 'S' || game->map[row][col] == 'E' 
				|| game->map[row][col] == 'W')
			{
				// Verificar si está en los bordes del mapa
				if (row == 0 || row == map_height - 1 || col == 0 || col == line_len - 1)
				{
					fprintf(stderr, "Error\nMap not closed by walls\n");
					ft_close_with_error(game);
				}
			}
			col++;
		}
		row++;
	}
}
