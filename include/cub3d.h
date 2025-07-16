<<<<<<< Updated upstream
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:06:37 by alba              #+#    #+#             */
/*   Updated: 2025/07/16 12:46:35 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef cub3d_H
# define cub3d_H

/************
* LIBRARIES *
************/

#include "mlx.h"
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

// Enumeración de direcciones cardinales para orientación del jugador
typedef enum e_direction
{
	NORTH,	// Norte
	SOUTH,	// Sur
	EAST,	// Este
	WEST	// Oeste
}	t_direction;

// Estructura para manejar el ángulo y rotación del jugador
typedef struct s_player_angle
{
	float	current_angle;	// Ángulo actual de la cámara/jugador
	float	angle_speed;	// Velocidad de rotación
	float	cos_angle;		// Coseno del ángulo (optimización)
	float	sin_angle;		// Seno del ángulo (optimización)
} t_angle;

// Estados de movimiento del jugador (teclas presionadas)
typedef struct s_player_move
{
	bool	forward;	// Moverse hacia adelante (W)
	bool	back;		// Moverse hacia atrás (S)
	bool	left;		// Moverse a la izquierda (A)
	bool	right;		// Moverse a la derecha (D)
}	t_move;

// Estados de rotación del jugador (teclas presionadas)
typedef struct s_player_rotate
{
	bool	left;	// Rotar hacia la izquierda (←)
	bool	right;	// Rotar hacia la derecha (→)
}	t_rotate;

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
	char	*addr;			// Dirección de datos de píxeles
	int		bits_per_pixel;	// Bits por píxel
	int		line_length;	// Longitud de línea en bytes
	int		endian;			// Orden de bytes
	int		width;			// Ancho de la imagen
	int		height;			// Alto de la imagen
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
	double	x;			// Posición X del jugador
	double	y;			// Posición Y del jugador
	double	dir_x;		// Vector dirección X (para raycasting)
	double	dir_y;		// Vector dirección Y (para raycasting)
	double	plane_x;	// Plano cámara X (para raycasting)
	double	plane_y;	// Plano cámara Y (para raycasting)
	
	// Campos nuevos integrados
	t_angle		angle;		// Información de ángulos
	t_direction	dir;		// Dirección cardinal
	t_move		move;		// Estados de movimiento
	t_rotate	rotate;		// Estados de rotación
}	t_player;

// Estructura del mapa del juego
typedef struct s_map
{
	char	**grid;			// Matriz 2D del mapa ('1'=pared, '0'=espacio)
	int		width;			// Ancho del mapa
	int		height;			// Alto del mapa
	int		player_count;	// Número de jugadores encontrados
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
	t_color	floor;			// Color del suelo
	t_color	ceiling;		// Color del techo
	int		map_rows;		// Filas del mapa
	int		map_col;		// Columnas del mapa
}	t_data;

// Estructura principal del juego (contiene todo)
typedef struct s_game
{
	void		*mlx;		// Conexión MLX
	void		*window;	// Ventana del juego
	t_img		screen;		// Imagen de la pantalla
	t_texture	textures;	// Todas las texturas
	t_player	player;		// Datos del jugador
	t_map		map;		// Datos del mapa
	t_data		data;		// Datos de parsing temporal
}	t_game;

/************
* FUNCTIONS *
************/

// Validación de argumentos y parseo de archivos
void	check_args(int argc, char **argv);		// Verifica argumentos del programa
void	open_file(char *argv, t_data *data);	// Abre y valida el archivo .cub
void	read_file(char *argv, t_data *data);	// Lee el contenido del archivo
void	file2array(char *argv, t_data *data);	// Convierte archivo a array

// Funciones de parseo de texturas
void	parse_no(char *no, t_data *data);	// Parsea textura norte
void	parse_so(char *so, t_data *data);	// Parsea textura sur
void	parse_we(char *we, t_data *data);	// Parsea textura oeste
void	parse_ea(char *ea, t_data *data);	// Parsea textura este

// Manejo de eventos de teclado
int		handle_key_press(int key, void *param);		// Cuando se presiona una tecla
int		handle_key_release(int key, void *param);	// Cuando se suelta una tecla

// Inicialización y limpieza del juego
void	init_game(t_game *game);								// Inicializa estructuras del juego
void	init_player(t_game *game, char direction, int x, int y);	// Inicializa posición del jugador
void	load_textures(t_game *game);							// Carga texturas desde archivos
int		close_win(t_game *game);								// Cierra ventana y libera memoria

// Utilidades de MLX
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);	// Pone un pixel en la imagen
int		get_texture_color(t_img *texture, int x, int y);		// Obtiene color de una textura

// Bucle del juego y eventos
int		game_loop(t_game *game);			// Bucle principal del juego
int		key_press(int keycode, t_game *game);	// Maneja teclas presionadas
int		key_release(int keycode, t_game *game);	// Maneja teclas soltadas

// Sistema de raycasting
void	raycast(t_game *game);		// Algoritmo principal de raycasting
void	render_frame(t_game *game);	// Renderiza un frame completo

// Utilidades generales
void	error_exit(char *message);		// Termina programa con error
void	free_game(t_game *game);		// Libera toda la memoria del juego
int		create_rgb(int r, int g, int b);	// Crea color RGB para MLX


/******
* MEM *
******/

#endif
>>>>>>> Stashed changes
