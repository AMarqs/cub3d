/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:52:39 by albmarqu          #+#    #+#             */
/*   Updated: 2025/07/17 15:51:47 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	frees(t_data *data)
{
	if (data)
		free(data);
}

void	error_alocating()
{
	write(2, "Error\nError allocating memory\n", 30);
	frees(t_data data);
	exit(EXIT_FAILURE);
}
