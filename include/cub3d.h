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

// Estructura para manejar los datos del raycasting
typedef struct t_ray
{
    double	camera_x;         // Posición del rayo en el plano de la cámara
    double	ray_dir_x;        // Dirección X del rayo
    double	ray_dir_y;        // Dirección Y del rayo
    int		map_x;            // Posición X en el mapa
    int		map_y;            // Posición Y en el mapa
    double	side_dist_x;      // Distancia desde el jugador al siguiente lado en X
    double	side_dist_y;      // Distancia desde el jugador al siguiente lado en Y
    double	delta_dist_x;     // Distancia entre lados en X
    double	delta_dist_y;     // Distancia entre lados en Y
    double	perp_wall_dist;   // Distancia perpendicular desde el jugador a la pared
    int		step_x;           // Dirección del paso en X (+1 o -1)
    int		step_y;           // Dirección del paso en Y (+1 o -1)
    int		hit;              // Indica si el rayo golpeó una pared (1) o no (0)
    int		side;             // Indica si el rayo golpeó una pared en X (0) o en Y (1)
}	t_ray;

typedef struct s_line
{
    int x0, y0;
    int x1, y1;
    int color;
}   t_line;

// Estructura principal del juego (contiene todo)
typedef struct t_game
{
	void		*mlx;		// Conexión MLX
	void		*window;	// Ventana del juego
	t_texture	textures;	// Todas las texturas
	t_player	player;		// Datos del jugador
	t_map		map;		// Datos del mapa
	t_data		data;		// Datos de parsing temporal
	t_ray		ray;		// Datos del raycasting
}	t_game;

/************
* FUNCTIONS *
************/

/* main.c */
int		main(int argc, char **argv);

/* init.c */
void	ft_initialize_graphics(t_game *game);
void	ft_initialize_player_position(t_game *game);
void	ft_load_textures(t_game *game);
void	ft_init(t_game *game);

/* init_utils.c */
void	ft_key_hook(mlx_key_data_t keydata, void *param);

/* elements.c */
void	ft_initialize_map(t_map *map);
void	ft_validate_elements_count(t_data *data);
void	ft_count_element_occurrences(t_data *data, char *line);

/* input.c */
void	ft_process_player_input(t_game *game);

/* key_hook.c */
void	ft_move_player_forward(t_game *game, double speed);
void	ft_move_player_left(t_game *game, double speed);
void	ft_move_player_backward(t_game *game, double speed);
void	ft_move_player_right(t_game *game, double speed);

/* key_utils.c */
void	ft_rotate_player(t_player *player, double direction);
int		ft_is_wall(t_data *data, double x, double y);

/* raycasting_utils.c */
void	ft_initialize_raycasting(t_ray *ray, t_game *game, int x);
void	ft_calculate_step_and_side_dist(t_ray *ray, t_game *game);
void	ft_perform_dda(t_ray *ray, t_game *game);
void	ft_calculate_wall_distance(t_ray *ray, t_game *game);

/* raycasting.c */
void	ft_calculate_projection(t_ray *ray);
void	ft_render_wall_slice(t_game *game, t_ray *ray, int column);
void	ft_raycast_all_columns(t_game *game);

/* render.c */
void	ft_draw_background(t_game *game);
void	ft_draw_vertical_line(void *window, t_line line);
void	ft_draw_column(t_game *game, int column, int start, int end);
void	ft_update_game(void *param);

/* textures.c */
char	*ft_find_texture_path(t_data *data, char identifier);
void	ft_load_texture(t_game *game, char identifier, t_img *texture);
void	ft_load_all_textures(t_game *game);

/* utils.c */
void	ft_close_with_error(t_data *data);
char	**ft_copy_matrix(char **src);
int		ft_is_whitespace(const char *str, int index);
int		ft_is_digit(int c);
int		ft_string_to_int(const char *str);

/* maps_utils.c */
int		ft_count_map_lines(const char *map_path, t_data *data);
void	ft_free_map(t_data *data);
void	ft_read_map_lines(int fd, char *line, t_data *data);
void	ft_read_map(t_data *data, char **argv);
void	ft_validate_map_name(char **argv);

#endif
