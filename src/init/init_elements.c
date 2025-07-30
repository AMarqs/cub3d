/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:29:55 by jortiz-m          #+#    #+#             */
/*   Updated: 2025/07/30 11:30:31 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		ft_close_with_error(game);
	}
	if (elem->c < 1 || elem->e < 1 || elem->f < 1
		|| elem->n < 1 || elem->s < 1 || elem->w < 1)
	{
		fprintf(stderr, "Error\nYou must specify each texture one time.\n");
		ft_close_with_error(game);
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
