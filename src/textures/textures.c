#include "cub3D.h"

char	*ft_search_texture(t_game *game, char c)
{
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
	return (ft_substr(game->map[i], j, ft_strlen(game->map[i])));
}

void	ft_load_textures(t_game *game)
{
	mlx_texture_t	*texture;
	char			*path;

	path = ft_search_texture(game, 'N');
	texture = mlx_load_png(path);
	if (!texture)
	{
		mlx_terminate(game->mlx);
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

	path = ft_search_texture(game, 'E');
	texture = mlx_load_png(path);
	if (!texture)
	{
		mlx_terminate(game->mlx);
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

	path = ft_search_texture(game, 'S');
	texture = mlx_load_png(path);
	if (!texture)
	{
		mlx_terminate(game->mlx);
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

	path = ft_search_texture(game, 'W');
	texture = mlx_load_png(path);
	if (!texture)
	{
		mlx_terminate(game->mlx);
		free(path);
		ft_close_with_error(game);
		exit(EXIT_FAILURE);
	}
	free(path);
	game->images.we = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
}
