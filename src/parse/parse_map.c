/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:30:52 by albmarqu          #+#    #+#             */
/*   Updated: 2025/07/17 21:46:17 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_map(t_data *data, int i)
{
	int		j;
	int		blank;

	blank = 0;
	while (data->map_data[i] && blank != 1)
	{
		j = 0;
		while (data->map_data[i] && data->map_data[i][j] != '\n' && blank != 1)
		{
			if (data->map_data[i][j] != ' ')
				blank = 1;
			j++;
		}
		i++;
	}
	i--;
	data->map = malloc((i + 1) * sizeof(char *));
	if (data->map == NULL)
		error_alocating(data);
	j = 0;
	while (data->map_data[i])
	{
		data->map[j] = data->map_data[i];
		i++;
		j++;
	}
///
	i = 0;
	printf("\nREAL MAPA\n");
	while (i < j)
		printf("%s", data->map[i++]);
	printf("\n");
///
}
