/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:29:55 by jortiz-m          #+#    #+#             */
/*   Updated: 2025/07/30 14:04:39 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



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
