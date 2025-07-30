/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:29:35 by jortiz-m          #+#    #+#             */
/*   Updated: 2025/07/30 12:29:37 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_search_texture_from_file(char *filename, char *prefix)
{
	int		fd;
	char	*line;
	char	*result;
	int		j;
	int		prefix_len;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	
	prefix_len = ft_strlen(prefix);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strncmp(line, prefix, prefix_len) == 0)
		{
			j = prefix_len;
			while (line[j] && line[j] <= 32)
				j++;
			result = ft_substr(line, j, ft_strlen(line) - j);
			// Remover salto de línea si existe
			if (result && ft_strlen(result) > 0 && result[ft_strlen(result) - 1] == '\n')
				result[ft_strlen(result) - 1] = '\0';
			free(line);
			close(fd);
			return (result);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (NULL);
}

char	*ft_search_texture(t_game *game, char c)
{
	// Esta función ahora es obsoleta, pero la mantenemos por compatibilidad
	// En su lugar deberíamos usar ft_search_texture_from_file
	int	i;
	int	j;

	i = -1;
	j = 1;
	while (game->map[++i])
	{
		if (game->map[i][0] == c)
		{
			while (game->map[i][++j] <= 32)
				;
			break ;
		}
	}
	if (!game->map[i])
		return (NULL);
	return (ft_substr(game->map[i], j, ft_strlen(game->map[i])));
}

void	ft_load_textures(t_game *game)
{
	mlx_texture_t	*texture;
	char			*path;

	path = ft_search_texture_from_file(game->filename, "NO");
	if (!path)
	{
		fprintf(stderr, "Error\nCould not find NO texture\n");
		ft_close_with_error(game);
	}
	texture = mlx_load_png(path);
	if (!texture)
	{
		free(path);
		ft_close_with_error(game);
		exit(EXIT_FAILURE);
	}
	free(path);
	game->images.no = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	ft_load_texture_east(game, texture);
	ft_load_texture_south(game, texture);
	ft_load_texture_west(game, texture);
}

void	ft_load_texture_east(t_game *game, mlx_texture_t *texture)
{
	char	*path;

	path = ft_search_texture_from_file(game->filename, "EA");
	if (!path)
	{
		fprintf(stderr, "Error\nCould not find EA texture\n");
		ft_close_with_error(game);
	}
	texture = mlx_load_png(path);
	if (!texture)
	{
		free(path);
		ft_close_with_error(game);
		exit(EXIT_FAILURE);
	}
	free(path);
	game->images.ea = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
}

void	ft_load_texture_south(t_game *game, mlx_texture_t *texture)
{
	char	*path;

	path = ft_search_texture_from_file(game->filename, "SO");
	if (!path)
	{
		fprintf(stderr, "Error\nCould not find SO texture\n");
		ft_close_with_error(game);
	}
	texture = mlx_load_png(path);
	if (!texture)
	{
		free(path);
		ft_close_with_error(game);
		exit(EXIT_FAILURE);
	}
	free(path);
	game->images.so = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
}

void	ft_load_texture_west(t_game *game, mlx_texture_t *texture)
{
	char	*path;

	path = ft_search_texture_from_file(game->filename, "WE");
	if (!path)
	{
		fprintf(stderr, "Error\nCould not find WE texture\n");
		ft_close_with_error(game);
	}
	texture = mlx_load_png(path);
	if (!texture)
	{
		free(path);
		ft_close_with_error(game);
		exit(EXIT_FAILURE);
	}
	free(path);
	game->images.we = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
}
