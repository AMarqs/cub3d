/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:06:37 by joritz-m              #+#    #+#         */
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

typedef struct s_ray
{
	double	camera_x;
	double	ray_x;
	double	ray_y;
	double	delta_distance_x;
	double	delta_distance_y;
	double	side_distance_x;
	double	side_distance_y;
	double	distance_to_wall;
	int		step_x;
	int		step_y;
	int		collision;
	int		map_x;
	int		map_y;
	int		side;
	int		wall_draw_start;
	int		wall_draw_end;
	int		wall_line_height;
}			t_ray;

typedef struct s_ray_aux
{
	mlx_image_t	*texture;
	double		wall_x;
	uint32_t	color;
	int			tex_y;
	int			tex_x;
	int			y;
	int			d;
}			t_ray_aux;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
}			t_player;

typedef struct s_control
{
	bool	w;
	bool	s;
	bool	a;
	bool	d;
	bool	left;
	bool	right;
}			t_control;

typedef struct s_images
{
	mlx_image_t	*no;
	mlx_image_t	*so;
	mlx_image_t	*ea;
	mlx_image_t	*we;
}				t_images;

typedef struct s_game
{
	char			**map;
	int				height;
	t_player		player;
	t_control		control;
	t_images		images;
	mlx_t			*mlx;
	mlx_image_t		*img;
	uint8_t			ceiling_r;
	uint8_t			ceiling_g;
	uint8_t			ceiling_b;
	uint8_t			floor_r;
	uint8_t			floor_g;
	uint8_t			floor_b;
}			t_game;

typedef struct s_elem
{
	int	n;
	int	s;
	int	e;
	int	w;
	int	c;
	int	f;
}		t_elem;

typedef struct s_start
{
	int	n;
	int	s;
	int	e;
	int	w;
}				t_start;

typedef struct s_line
{
	int			x;
	int			y_start;
	int			y_end;
	uint32_t	color;
}				t_line;

/************
* FUNCTIONS *
************/

/**********++****HOOK***********************/

/*KEY_HOOK*/
void	key_hook(mlx_key_data_t keydata, void *param);

/********************INIT*******************/
/*INIT*/
void        ft_init_game(t_game *game);
void	    ft_set_player_plane(t_game *game, int x, int y);
void	    ft_set_player_direction(t_game *game, int x, int y);
void	    ft_init_player_position(t_game *game);
void	    ft_init(t_game *game);

/*INIT_ELEMEMTS*/
void    	ft_init_elem(t_elem *elem);
void	    ft_validate_element_counts(t_game *game, t_elem *elem);
void	    ft_check_elements(t_game *game, int i, t_elem *elem);
void	    ft_init_game(t_game *game);

/**************INPUT*********************/
/*INPUT_UTILS*/
void	    ft_rotate_player(t_player *p, double dir);
int		    ft_is_wall(t_game *game, double x, double y);

/*INPUT*/
void	    ft_handle_input(void *param);

/****************RAYCASTING*****************/
/*RAYCASTING_UTILS*/
void	    ft_calculate_projection(t_ray	*ray);
uint32_t	ft_get_pixel_from_texture(mlx_image_t *img, int x, int y);
void	    ft_draw_wall_slice_with_aux(t_game *game, t_ray *ray, int x, t_ray_aux *aux);
void	    ft_draw_wall_slice(t_game *game, t_ray *ray, int x);
void	    ft_raycast_all_columns(t_game *game);

/****************RENDER*************************/
/*RENDER*/
void	ft_draw_background(t_game *game);
void	ft_draw_vertical_line(mlx_image_t *img, t_line line);
void	ft_draw_column(t_game *game, int x, int start, int end);
void	ft_update_game(void *param);

/****************TEXTURES*************************/
/*TEXTURES*/
char	*ft_search_texture(t_game *game, char c);
void	ft_load_textures(t_game *game);
void	ft_load_texture_east(t_game *game, mlx_texture_t *texture);
void	ft_load_texture_south(t_game *game, mlx_texture_t *texture);
void	ft_load_texture_west(t_game *game, mlx_texture_t *texture);

/****************UTILS*************************/
/*MAPS_UTILS*/
int	ft_count_lines(char *map, t_game *game);
void	ft_free_map(t_game *game);
void	ft_read_map_lines(int fd, char *line, t_game *game);
void	ft_read_map(t_game *game, char **argv);
void	ft_check_name(char **argv);

/*UTILS*/
void	ft_close_with_error(t_game *game);
char	**ft_cpy_matrix(char **src);
int	ft_is_space(const char *str, int counter);

/*******************MAIN************************* */
/*MAIN*/
int	main(int argc, char **argv);

#endif
