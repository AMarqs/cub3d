/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:01:23 by jortiz-m          #+#    #+#             */
/*   Updated: 2025/07/16 12:14:56 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	int 	i;
	
	i = 0;
	check_args(argc, argv);
	printf("Good arguments\n");
	game = malloc(sizeof(t_game));
	if (game == NULL)
		error_exit("Error allocating memory for game");
	// Initialize the data structure
	ft_memset(game, 0, sizeof(t_game));
	// Parse the file
	open_file(argv[1], &game->data);
	printf("Correct file, %d lines\n", game->data.file_rows);
	read_file(argv[1], &game->data);
	// Debug print map
	printf("\nMAPA\n");
	while (i <= game->data.file_rows)
		printf("%s", game->data.map_data[i++]);
	init_game(game);
	init_player(game, 'N', 5, 5); // Default player position and direction
	mlx_loop(game->mlx);
	return (0);
}
