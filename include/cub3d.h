/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:06:37 by albmarqu          #+#    #+#             */
/*   Updated: 2025/07/17 17:51:34 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/************
* LIBRARIES *
************/

# include "lib/MLX42/include/MLX42/MLX42.h"
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

/*********
* MACROS *
*********/

# define WIN_WIDTH		1920
# define WIN_HEIGHT		1080
# define TEXTURE_SIZE	64

# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100
# define KEY_LEFT  		65361
# define KEY_RIGHT 		65363
# define KEY_ESC  		65307

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

typedef struct s_count
{
	int	total;
	int	count_no;
	int	count_so;
	int	count_we;
	int	count_ea;
	int	count_f;
	int	count_c;
}	t_count;

typedef struct s_data
{
	int		file_rows;
	char	**map_data;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	t_color	floor;
	t_color	ceiling;
	
	int		map_rows;
	int		map_col;
}	t_data;

/************
* FUNCTIONS *
************/


//// PARSE ////

void	check_args(int argc, char **argv);
void	open_file(char *argv, t_data *data);
void	read_file(char *argv, t_data *data);
void	file2map(char *argv, t_data *data);
void	parse_textures(t_data *data);

void	texture_type(t_data *data, int i, t_count *count);
void	parse_no(char *no, t_data *data);
void	parse_so(char *so, t_data *data);
void	parse_we(char *we, t_data *data);
void	parse_ea(char *ea, t_data *data);
void	open_texture_file(char *path);
void	texture_error(void);

void	texture_color(t_data *data, int i, t_count *count);
void	parse_f(char *f, t_data *data);
void	parse_c(char *c, t_data *data);

void	check_count(t_count *count);

#endif