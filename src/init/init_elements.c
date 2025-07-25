#include "cub3D.h"

void	ft_init_elem(t_elem *elem)
{
	elem->c = 0;
	elem->f = 0;
	elem->e = 0;
	elem->n = 0;
	elem->s = 0;
	elem->w = 0;
}

void	ft_validate_element_counts(t_game *game, t_elem *elem)
{
	if (elem->c > 1 || elem->e > 1 || elem->f > 1
		|| elem->n > 1 || elem->s > 1 || elem->w > 1)
	{
		fprintf(stderr, "Error\nYou must specify each texture one time.\n");
		ft_bad_close(game);
	}
	if (elem->c < 1 || elem->e < 1 || elem->f < 1
		|| elem->n < 1 || elem->s < 1 || elem->w < 1)
	{
		fprintf(stderr, "Error\nYou must specify each texture one time.\n");
		ft_bad_close(game);
	}
}

void	ft_check_elements(t_game *game, int i, t_elem *elem)
{
	if (game->map[i][0] == 'N')
		++elem->n;
	if (game->map[i][0] == 'S')
		++elem->s;
	if (game->map[i][0] == 'W')
		++elem->w;
	if (game->map[i][0] == 'E')
		++elem->e;
	if (game->map[i][0] == 'F')
		++elem->f;
	if (game->map[i][0] == 'C')
		++elem->c;
}

void	ft_init_game(t_game *game)
{
	if (!game)
	{
		fprintf(stderr, "Error\nCould not allocate the map");
		exit(EXIT_FAILURE);
	}
	game->map = NULL;
	game->height = 0;
}
