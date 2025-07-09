/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alba <alba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:29:44 by albmarqu          #+#    #+#             */
/*   Updated: 2025/07/09 13:12:34 by alba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	1. Compruebo si el numero de argumentos es 2: el nombre del programa en si
	   y el nombre del archivo para el mapa.
	2. Compruebo si el archivo del mapa tiene como extensión .cub
*/
void	check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		write(2, "Error\nWrong number of arguments\n", 32);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp((argv[1] + ft_strlen(argv[1]) - 4), ".cub", 4))
	{
		write(2, "Error\nBad extension\n", 20);
		exit(EXIT_FAILURE);
	}
}