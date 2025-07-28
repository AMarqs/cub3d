/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:06:37 by alba              #+#    #+#             */
/*   Updated: 2025/07/28 11:08:08 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H


/************
* LIBRARIES *
************/

#include "lib/MLX42/include/MLX42/MLX42.h"
#include "lib/libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

/*********
* MACROS *
*********/

# define TITLE 				"cub3D"
# define WIDTH 				1920
# define HEIGHT 			1080
# define COLLISION_MARGIN 	0.2

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

// Estructura para colores RGB
typedef struct s_color
{
	int	r;	// Componente rojo (0-255)
	int	g;	// Componente verde (0-255)
	int	b;	// Componente azul (0-255)
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

// Estructura para imágenes de MLX (texturas y pantalla)
typedef struct s_img
{
    int width;
    int height;
    void *data;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_img;

// Estructura para las 4 texturas de las paredes
typedef struct s_texture
{
    mlx_image_t *img;
} t_texture;

typedef struct s_textures
{
    t_texture east;
    t_texture west;
    t_texture south;
    t_texture north;
} t_textures;

// Estructura principal del jugador
typedef struct s_player
{
    double x;
    double y;
    double dir_x;    // Dirección del jugador en X
    double dir_y;    // Dirección del jugador en Y
    double plane_x;  // Plano de cámara en X
    double plane_y;  // Plano de cámara en Y
}	t_player;

// Estructura del mapa del juego
typedef struct s_map
{
	t_color		floor;			// Color del suelo
	t_color		ceiling;		// Color del techo
}	t_map;

// Estructura temporal para parsear el archivo .cub
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

size_t	ft_strlen(const char *s);
int		ft_isletter(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*get_next_line(int fd);

void	check_args(int argc, char **argv);
void	open_file(char *argv, t_data *data);
void	read_file(char *argv, t_data *data);
void	file2array(char *argv, t_data *data);

// void	parse_textures(t_data *data);
// void	parse_no(char *no, t_data *data);
// void	parse_so(char *so, t_data *data);
// void	parse_we(char *we, t_data *data);
// void	parse_ea(char *ea, t_data *data);


/******
* MEM *
******/

#endif
