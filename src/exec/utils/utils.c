/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:29:47 by jortiz-m          #+#    #+#             */
/*   Updated: 2025/07/31 11:39:09 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_close_with_error(t_game *game)
{
	if (game)
	{
		if (game->mlx)
			mlx_terminate(game->mlx);
		frees(game);
	}
	exit(EXIT_FAILURE);
}
