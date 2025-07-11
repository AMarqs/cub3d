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

void texture_error(void)
{
    write(2, "Error\nInvalid texture data\n", 27);
    exit(EXIT_FAILURE);
}

void open_texture_file(char *path)
{
    int fd;

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

void parse_no(char *no, t_data *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    no += 2;
    while (*no == ' ')
        no++;
    while (no[i] && no[i] != '\n')
    {
        if (!ft_isletter(no[i]) && no[i] != '/' && no[i] != '.')
            texture_error();
        data->no_texture[j] = no[i];
        i++;
        j++;
    }
    data->no_texture[j] = '\0';
    open_texture_file(data->no_texture);
}

void parse_so(char *so, t_data *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    so += 2;
    while (*so == ' ')
        so++;
    while (so[i] && so[i] != '\n')
    {
        if (!ft_isletter(so[i]) && so[i] != '/' && so[i] != '.')
            texture_error();
        data->so_texture[j] = so[i];
        i++;
        j++;
    }
    data->so_texture[j] = '\0';
    open_texture_file(data->so_texture);
}

void parse_we(char *we, t_data *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    we += 2;
    while (*we == ' ')
        we++;
    while (we[i] && we[i] != '\n')
    {
        if (!ft_isletter(we[i]) && we[i] != '/' && we[i] != '.')
            texture_error();
        data->we_texture[j] = we[i];
        i++;
        j++;
    }
    data->we_texture[j] = '\0';
    open_texture_file(data->we_texture);
}

void parse_ea(char *ea, t_data *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    ea += 2;
    while (*ea == ' ')
        ea++;
    while (ea[i] && ea[i] != '\n')
    {
        if (!ft_isletter(ea[i]) && ea[i] != '/' && ea[i] != '.')
            texture_error();
        data->ea_texture[j] = ea[i];
        i++;
        j++;
    }
    data->ea_texture[j] = '\0';
    open_texture_file(data->ea_texture);
}
