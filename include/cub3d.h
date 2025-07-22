/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:06:37 by albmarqu          #+#    #+#             */
/*   Updated: 2025/07/21 21:35:34 by albmarqu         ###   ########.fr       */
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
# include <limits.h>


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
	char	*map_aux;
	t_count	*count;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	t_color	*floor;
	t_color	*ceiling;
	char	**map;
}	t_data;


/************
* FUNCTIONS *
************/


//// PARSE ////

void	check_args(int argc, char **argv, t_data *data);
void	open_file(char *argv, t_data *data);
void	read_file(char *argv, t_data *data);
void	file2map(int file, t_data *data);
void	parse_info(t_data *data);
void	init_counters(t_count *count);
void	check_count(t_count *count, t_data *data);
// Textures
void	parse_texture(char *map, t_data *data);
void	parse_no(char *no, t_data *data);
void	parse_so(char *so, t_data *data);
void	parse_we(char *we, t_data *data);
void	parse_ea(char *ea, t_data *data);
void	open_texture_file(char *path, t_data *data);
// Colors
void	parse_color(char *map, t_data *data);
void	parse_f(char *f, t_data *data);
void	parse_c(char *c, t_data *data);
void	count_commas(char *str, t_data *data);
long	color_range(const char *str, t_data *data);
long	ft_atol(const char *str);
// Map
void	parse_map(t_data *data, int i);
void	parse_char(t_data *data);
void	parse_floor(t_data *data);
void	correct_floor(t_data *data, int row, int col);
// Player
void	parse_player(t_data *data);
void	good_player(t_data *data, int row, int col);


//// ERRORS ////

void	print_error(char *str, t_data *data);
void	frees(t_data *data);
void	*ft_freematrix(char **matrix);


#endif