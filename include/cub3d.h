/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:06:37 by joritz-m              #+#    #+#             */
/*   Updated: 2025/07/16 19:24:39 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef cub3d_H
# define cub3d_H

/************
* LIBRARIES *
************/

#include "lib/MLX42/include/MLX42/MLX42.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
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

// Estructura para imágenes de MLX (texturas y pantalla)
typedef struct s_img
{
	void	*img;			// Puntero a la imagen MLX
	int		bits_per_pixel;	// Bits por píxel
	int		line_length;	// Longitud de línea en bytes
	int		endian;			// Orden de bytes
}	t_img;

// Estructura para las 4 texturas de las paredes
typedef struct s_texture
{
	t_img	north;	// Textura pared norte
	t_img	south;	// Textura pared sur
	t_img	east;	// Textura pared este
	t_img	west;	// Textura pared oeste
}	t_texture;

// Estructura principal del jugador
typedef struct s_player
{
	float	x;			// Posición X del jugador
	float	y;			// Posición Y del jugador
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
	int		file_rows;		// Número de líneas del archivo
	char	**map_data;		// Datos del archivo en array
	char	*no_texture;	// Ruta textura norte
	char	*so_texture;	// Ruta textura sur
	char	*we_texture;	// Ruta textura oeste
	char	*ea_texture;	// Ruta textura este
}	t_data;

// Estructura principal del juego (contiene todo)
typedef struct s_game
{
	void		*mlx;		// Conexión MLX
	void		*window;	// Ventana del juego
	t_texture	textures;	// Todas las texturas
	t_player	player;		// Datos del jugador
	t_map		map;		// Datos del mapa
	t_data		data;		// Datos de parsing temporal
}	t_game;

/************
* FUNCTIONS *
************/

#endif
