/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:29:47 by jortiz-m          #+#    #+#             */
/*   Updated: 2025/07/30 19:00:01 by albmarqu         ###   ########.fr       */
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

int	ft_is_space(const char *str, int counter)
{
	if ((str[counter] >= 9 && str[counter] <= 13) || str[counter] == 32)
		return (1);
	return (0);
}
