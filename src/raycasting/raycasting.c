#include "cub3d.h"

/**
 * ft_calculate_projection - Calcula la proyección de la pared en la pantalla.
 * @ray: Puntero a la estructura del rayo.
 * 
 * Determina la altura de la línea de la pared en la pantalla y los límites
 * de dibujo (inicio y fin) basados en la distancia perpendicular a la pared.
 */
void	ft_calculate_projection(t_ray *ray)
{
    int	line_height;
    int	draw_start;
    int	draw_end;

    line_height = (int)(HEIGHT / ray->perp_wall_dist);
    draw_start = -line_height / 2 + HEIGHT / 2;
    if (draw_start < 0)
        draw_start = 0;
    draw_end = line_height / 2 + HEIGHT / 2;
    if (draw_end >= HEIGHT)
        draw_end = HEIGHT - 1;
    ray->draw_start = draw_start;
    ray->draw_end = draw_end;
    ray->line_height = line_height;
}

/**
 * ft_render_wall_slice - Renderiza una columna completa de la pared.
 * @game: Puntero a la estructura principal del juego.
 * @ray: Puntero a la estructura del rayo.
 * @column: Índice de la columna actual en la pantalla.
 * 
 * Determina la textura y las coordenadas de la pared golpeada por el rayo,
 * y dibuja la columna correspondiente en la pantalla.
 */
void	ft_render_wall_slice(t_game *game, t_ray *ray, int column)
{
    t_img *texture;
    double		wall_x;
    int			texture_x;
    int			y;

    if (ray->side == 0)
        wall_x = game->player.y + ray->perp_wall_dist * ray->ray_dir_y;
    else
        wall_x = game->player.x + ray->perp_wall_dist * ray->ray_dir_x;
    wall_x -= floor(wall_x);

    if (ray->side == 0 && ray->ray_dir_x > 0)
        texture = game->textures.east.img;
    else if (ray->side == 0 && ray->ray_dir_x < 0)
        texture = game->textures.west.img;
    else if (ray->side == 1 && ray->ray_dir_y > 0)
        texture = game->textures.south.img;
    else
        texture = game->textures.north.img;

    texture_x = (int)(wall_x * texture->width);
    if ((ray->side == 0 && ray->ray_dir_x < 0) || (ray->side == 1 && ray->ray_dir_y > 0))
        texture_x = texture->width - texture_x - 1;

    y = ray->draw_start;
    while (y < ray->draw_end)
    {
        int d = y * 256 - HEIGHT * 128 + ray->line_height * 128;
        int texture_y = ((d * texture->height) / ray->line_height) / 256;
        uint32_t color = mlx_get_pixel(texture, texture_x, texture_y);
        mlx_put_pixel(game->window, column, y, color);
        y++;
    }
}

/**
 * ft_raycast_all_columns - Realiza el raycasting para todas las columnas de la pantalla.
 * @game: Puntero a la estructura principal del juego.
 * 
 * Itera sobre cada columna de la pantalla, calcula el raycasting y renderiza
 * la pared correspondiente.
 */
void	ft_raycast_all_columns(t_game *game)
{
    int		column;
    t_ray	ray;

    column = -1;
    while (++column < WIDTH)
    {
        ft_initialize_raycasting(&ray, game, column);
        ft_calculate_step_and_side_dist(&ray, game);
        ft_perform_dda(&ray, game);
        ft_calculate_wall_distance(&ray, game);
        ft_calculate_projection(&ray);
        ft_render_wall_slice(game, &ray, column);
    }
}
