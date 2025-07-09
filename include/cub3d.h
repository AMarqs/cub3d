/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alba <alba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:06:37 by alba              #+#    #+#             */
/*   Updated: 2025/07/09 13:08:00 by alba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/************
* LIBRARIES *
************/

//# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

/*********
* COLORS *
*********/

# define RD		"\033[1;91m"
# define PR		"\033[4;95m"
# define CI		"\033[0;96m"
# define GR		"\033[0;92m"
# define PI		"\033[0;94m"
# define FF		"\033[0;97m"
# define RES	"\033[0m"

/*************
* STRUCTURES *
*************/

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_data
{
	//char	*line;
	int		file_rows;
	char	**map_data;


	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	t_color	floor;
	t_color	ceiling;
	int		map_rows;
	int		map_col;
	int		x;
	int		y;
	char	dir;
}	t_data;

/************
* FUNCTIONS *
************/

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*get_next_line(int fd);

void	check_args(int argc, char **argv);
void	open_file(char *argv, t_data *data);
void	read_file(char *argv, t_data *data);
void	parse_textures(t_data *data);

/******
* MEM *
******/

#endif