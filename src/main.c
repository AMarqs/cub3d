/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:01:23 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/07/11 10:30:10 by albmarqu         ###   ########.fr       */
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
	printf("\nMAPA\n");
	while (i <= data->file_rows)
		printf("%s", data->map_data[i++]);
//
	return (0);
}