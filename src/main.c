#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	(void)argv;
	if (argc == 2)
	{
		game = malloc(sizeof(t_game));
        if (!game)
            return (EXIT_FAILURE);
        ft_init(game);
        ft_free_map(&game->data);
        free(game);
	}
	else
	{
		fprintf(stderr, "Error\ncub3D needs map.cub\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
