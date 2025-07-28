/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:01:23 by albmarqu          #+#    #+#             */
/*   Updated: 2025/07/28 11:30:16 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parser(int argc, char **argv, t_data *data)
{
	check_args(argc, argv, data);
	// write(1, "Good arguments\n", 15);
	open_file(argv[1], data);
	// printf("Correct file, %d lines\n", data->file_rows);
	read_file(argv[1], data);
//
	// int i = 0;
	// printf("\nMAPA\n");
	// while (i <= data->file_rows)
	// 	printf("%s", data->map_data[i++]);
	// printf("\n");
//
	parse_info(data);
	// write(1, "Good map info\n", 14);
	// prepare_game(data);
}

void	initiation(t_data *data, t_init	*init)
{
	init->pos_dir = 0;
	init->pos_x = 0;
	init->pos_y = 0;
	player_pos(data, init);
	
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_init	*init;
	t_game	*game;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		print_error("Error allocating memory\n", data);
	// Initialize the data structure
	ft_memset(data, 0, sizeof(t_data)); // esto no me acuerdo para que era
	init = malloc(sizeof(t_init));
	if (init == NULL)
		print_error("Error allocating memory\n", data); // CAMBIAR LA LIBERACION DE MEMORIA A INIT
	// Initialize the init structure
	ft_memset(init, 0, sizeof(t_init)); // esto no me acuerdo para que era
	parser(argc, argv, data);
	initiation(data, init);
	frees(data);
	////
	game = malloc(sizeof(t_game));
    if (!game)
        return (EXIT_FAILURE);
    ft_init(game);
    // ft_free_map(&game->data);
    free(game);
	return (EXIT_SUCCESS);
}
