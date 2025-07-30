/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:30:25 by jortiz-m          #+#    #+#             */
/*   Updated: 2025/07/30 18:56:08 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parser(int argc, char **argv, t_game *game)
{
	check_args(argc, argv, game);
	open_file(argv[1], game);
	read_file(argv[1], game);
	parse_info(game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		print_error("Error allocating memory\n", game);
	parser(argc, argv, game);

	ft_init(game);
	frees(game);
	// free(game);
	return (EXIT_SUCCESS);
}
