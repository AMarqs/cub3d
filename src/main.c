/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:30:25 by jortiz-m          #+#    #+#             */
/*   Updated: 2025/07/30 13:57:50 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2)
	{
		game = ft_calloc(1, sizeof(t_game));
		if (!game)
			return (EXIT_FAILURE);
		check_args(argc, argv, game->data);
		open_file(argv[1], game->data);
		read_file(argv[1], game->data);
		parse_info(game->data);
		ft_init(game);
		frees(game->data);
		free(game);
	}
	else
	{
		fprintf(stderr, "Error\ncub3D needs map.cub\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
