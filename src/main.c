/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alba <alba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:01:23 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/07/09 13:11:46 by alba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	check_args(argc, argv);
	printf("Good arguments\n");
	data = malloc(sizeof(t_data));
	if (data == NULL)
	{
		write(2, "Error\nError allocating memory\n", 30);
		exit(EXIT_FAILURE);
	}
	open_file(argv[1], data);
	printf("Correct file, %d lines\n", data->file_rows);
	read_file(argv[1], data);
//
	int i = 0;
	printf("MAPA\n");
	while (i <= data->file_rows)
		printf("%s", data->map_data[i++]);
//
	return (0);
}