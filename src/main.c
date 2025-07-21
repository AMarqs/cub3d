/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:01:23 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/07/21 20:12:19 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parser(int argc, char **argv, t_data *data)
{
	check_args(argc, argv, data);
	write(1, "Good arguments\n", 15);
	open_file(argv[1], data);
	// printf("Correct file, %d lines\n", data->file_rows);
	read_file(argv[1], data);
//
	// int i = 0;
	// printf("\nMAPA\n");
	// while (i <= data->file_rows)
	// 	printf("%s", data->map_data[i++]);
	// printf("\n");
//
	parse_info(data);
	write(1, "Good map info\n", 14);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		print_error("Error allocating memory\n", data);
	// Initialize the data structure
	ft_memset(data, 0, sizeof(t_data)); // esto no me acuerdo para que era
	parser(argc, argv, data);
	frees(data);
	return (0);
}
