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

void	parse_route(char *route, t_data *data)
{
	int	i;

	i = 2;
	while (route[i] == ' ')
		i++;
	while (route[i] && route[i] != '\n')
	{
		if (!ft_isascii(route[i]) && route[i] != '/' && route[i] != '.') //// QUE PUEDE SER UNA RUTA ????
			print_error("Invalid texture data\n", data);
		i++;
	}
}

void	parse_no(char *no, t_data *data)
{
	int		len;
	char	*aux;

	len = ft_strlen(no);
	parse_route(no, data);
	aux = ft_substr(no, 2, len);
	data->no_texture = ft_strtrim(aux, " \n");
	free(aux);
	open_texture_file(data->no_texture, data);
}

void	parse_so(char *so, t_data *data)
{
	int		len;
	char	*aux;

	len = ft_strlen(so);
	parse_route(so, data);
	aux = ft_substr(so, 2, len);
	data->so_texture = ft_strtrim(aux, " \n");
	free(aux);
	open_texture_file(data->so_texture, data);
}

void	parse_we(char *we, t_data *data)
{
	int		len;
	char	*aux;

	len = ft_strlen(we);
	parse_route(we, data);
	aux = ft_substr(we, 2, len);
	data->we_texture = ft_strtrim(aux, " \n");
	free(aux);
	open_texture_file(data->we_texture, data);
}

void	parse_ea(char *ea, t_data *data)
{
	int		len;
	char	*aux;

	len = ft_strlen(ea);
	parse_route(ea, data);
	aux = ft_substr(ea, 2, len);
	data->ea_texture = ft_strtrim(aux, " \n");
	free(aux);
	open_texture_file(data->ea_texture, data);
}
