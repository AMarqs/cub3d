/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:06:37 by joritz-m          #+#    #+#             */
/*   Updated: 2025/08/05 17:31:54 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/***************************** LIBRARIES **************************************/

# include "lib/MLX42/include/MLX42/MLX42.h"
# include "lib/libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/********************************* MACROS *************************************/

# define TITLE "cub3D"
# define WIDTH 1920
# define HEIGHT 1080
# define COLLISION_MARGIN 0.2

/******MOVEMENT*******/

# define MOVE_SPEED 0.05
# define ROT_SPEED 0.05

/******COLORS*******/

# define RD "\033[1;91m"
# define PR "\033[4;95m"
# define CI "\033[0;96m"
# define GR "\033[0;92m"
# define PI "\033[0;94m"
# define FF "\033[0;97m"
# define RES "\033[0m"

/***************************** STRUCTURES *************************************/

/***************
 *    PARSE    *
 ***************/

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct s_count
{
	int			no;
	int			so;
	int			we;
	int			ea;
	int			f;
	int			c;
	int			total;
	int			count_no;
	int			count_so;
	int			count_we;
	int			count_ea;
	int			count_f;
	int			count_c;
}				t_count;

typedef struct s_data
{
	char		**map_data;
	char		*map_aux;
	char		**map;
	char		*no_texture;
	char		*so_texture;
	char		*ea_texture;
	char		*we_texture;
	int			file_rows;
	int			map_size;
	char		**f_rgb;
	char		**c_rgb;
	t_color		*floor;
	t_color		*ceiling;
	t_count		*count;
}				t_data;

/***************
 *     EXEC    *
 ***************/

typedef struct s_ray
{
	double		camera_x;
	double		ray_x;
	double		ray_y;
	double		delta_distance_x;
	double		delta_distance_y;
	double		side_distance_x;
	double		side_distance_y;
	double		distance_to_wall;
	int			step_x;
	int			step_y;
	int			collision;
	int			map_x;
	int			map_y;
	int			side;
	int			wall_draw_start;
	int			wall_draw_end;
	int			wall_line_height;
}				t_ray;

typedef struct s_ray_aux
{
	mlx_image_t	*texture;
	double		wall_x;
	uint32_t	color;
	int			tex_y;
	int			tex_x;
	int			y;
	int			d;
}				t_ray_aux;

typedef struct s_player
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rot_speed;
}				t_player;

typedef struct s_control
{
	bool		w;
	bool		s;
	bool		a;
	bool		d;
	bool		left;
	bool		right;
}				t_control;

typedef struct s_images
{
	mlx_image_t	*no;
	mlx_image_t	*so;
	mlx_image_t	*ea;
	mlx_image_t	*we;
}				t_images;

typedef struct s_line
{
	int			x;
	int			y_start;
	int			y_end;
	uint32_t	color;
}				t_line;

typedef struct s_game
{
	t_data		*data;
	t_player	player;
	t_control	control;
	t_images	images;
	mlx_t		*mlx;
	mlx_image_t	*img;
}				t_game;

/******************FUNCTIONS******************/

/**************
 *    MAIN    *
 **************/

int				main(int argc, char **argv);

/***************
 *    PARSE    *
 ***************/

void			check_args(int argc, char **argv, t_game *game);
void			open_file(char *argv, t_game *game);
void			read_file(char *argv, t_game *game);
void			file2map(int file, t_game *game);
void			parse_info(t_game *game);

/* COUNTERS */
void			init_counters(t_game *game);
void			check_count(t_count *count, t_game *game);

/* TEXTURES */
void			parse_texture(char *map, t_game *game);
void			parse_direction(t_game *game, char *dir, char **path);
void			open_texture_file(char *path, t_game *game);

/* COLORS */
void			parse_color(char *map, t_game *game);
void			parse_f(char *f, t_game *game);
void			parse_c(char *c, t_game *game);
void			count_commas(char *str, t_game *game);
long			color_range(const char *str, t_game *game);
long			ft_atol(const char *str);

/* MAP */
void			parse_map(t_game *game, int i);
void			parse_char(t_game *game);

/* PLAYER */
void			parse_player(t_game *game);
void			good_player(t_game *game, int row, int col);

/* FLOOR */
void			parse_floor(t_game *game);
void			correct_floor(t_game *game, int row, int col);
void			new_line(t_game *game, int row);

/***************
 *     INIT    *
 ***************/

/******************INIT******************/

/* INIT */
void			ft_init_mlx(t_game *game);
void			ft_set_player_plane(t_game *game, int x, int y);
void			ft_set_player_direction(t_game *game, int x, int y);
void			ft_init_player_position(t_game *game);
void			ft_init(t_game *game);

/***************
 *     EXEC    *
 ***************/

/******************HOOKS******************/

/* KEY_HOOK */
void			key_hook(mlx_key_data_t keydata, void *param);

/******************INPUT******************/

/* INPUT_UTILS */
void			ft_rotate_player(t_player *p, double dir);
int				ft_is_wall(t_game *game, double x, double y);

/* INPUT */
void			ft_handle_input(void *param);

/******************RAYCASTING******************/

/* RAYCASTING_UTILS */
void			ft_calculate_projection(t_ray *ray);
uint32_t		ft_get_pixel_from_texture(mlx_image_t *img, int x, int y);
void			ft_draw_wall_with_aux(t_game *game, t_ray *ray, int x,
					t_ray_aux *aux);
void			ft_draw_wall_slice(t_game *game, t_ray *ray, int x);
void			ft_raycast_all_columns(t_game *game);

/* RAYCASTING */
void			ft_init_ray(t_game *game, t_ray *ray, int x);
void			ft_calculate_steps_and_sidedist(t_game *game, t_ray *ray);
void			ft_perform_dda(t_game *game, t_ray *ray);

/******************RENDER******************/

/* RENDER */
void			ft_draw_background(t_game *game);
void			ft_draw_vertical_line(mlx_image_t *img, t_line line);
void			ft_update_game(void *param);

/******************TEXTURE******************/

/* TEXTURE */

void			ft_load_textures(t_game *game);
void			ft_load_texture_north(t_game *game);
void			ft_load_texture_east(t_game *game);
void			ft_load_texture_south(t_game *game);
void			ft_load_texture_west(t_game *game);

/*****************
 *     ERRORS    *
 *****************/

void			print_error(char *str, t_game *game);
void			frees(t_game *game);
void			free_data(t_data *data);
void			*ft_freematrix(char **matrix);

#endif
