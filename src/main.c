/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:30:25 by jortiz-m          #+#    #+#             */
/*   Updated: 2025/07/30 11:30:30 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2)
	{
		game = malloc(sizeof(t_game));
		if (!game)
			return (EXIT_FAILURE);
		ft_check_name(argv);
		ft_read_map(game, argv);
		ft_init(game);
		ft_free_map(game);
		free(game);
	}
	else
	{
		fprintf(stderr, "Error\ncub3D needs map.cub\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
