/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:08:38 by albmarqu          #+#    #+#             */
/*   Updated: 2025/07/10 13:08:38 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	open_texture_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nNo such file or directory: ", 32);
		write(2, path, ft_strlen(path));
		write(2, "\n", 1);
		exit(EXIT_FAILURE);
	}
	close(fd);
}

void	parse_route(char *route)
{
	int	i;

	i = 2;
	while (route[i] == ' ')
		i++;
	while (route[i] && route[i] != '\n')
	{
		if (ft_isletter(route[i]) && route[i] != '/' && route[i] != '.')
		{
			write(2, "Error\nInvalid texture data\n", 27);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	parse_no(char *no, t_data *data)
{
	int		len;
	char	*aux;

	len = ft_strlen(no);
	parse_route(no);
	aux = ft_substr(no, 2, len);
	data->no_texture = ft_strtrim(aux, " \n");
	free(aux);
	open_texture_file(data->no_texture);
}

void	parse_so(char *so, t_data *data)
{
	int		len;
	char	*aux;

	len = ft_strlen(so);
	parse_route(so);
	aux = ft_substr(so, 2, len);
	data->so_texture = ft_strtrim(aux, " \n");
	free(aux);
	open_texture_file(data->so_texture);
}

void	parse_we(char *we, t_data *data)
{
	int		len;
	char	*aux;

	len = ft_strlen(we);
	parse_route(we);
	aux = ft_substr(we, 2, len);
	data->we_texture = ft_strtrim(aux, " \n");
	free(aux);
	open_texture_file(data->we_texture);
}

void	parse_ea(char *ea, t_data *data)
{
	int		len;
	char	*aux;

	len = ft_strlen(ea);
	parse_route(ea);
	aux = ft_substr(ea, 2, len);
	data->ea_texture = ft_strtrim(aux, " \n");
	free(aux);
	open_texture_file(data->ea_texture);
}
