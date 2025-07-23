#include "cub3d.h"

/**
 * ft_initialize_raycasting - Inicializa los valores necesarios para el raycasting.
 * @ray: Puntero a la estructura del rayo.
 * @game: Puntero a la estructura principal del juego.
 * @x: Índice de la columna actual en la pantalla.
 * 
 * Calcula la dirección inicial del rayo, las posiciones en el mapa y las distancias delta.
 */
void	ft_initialize_raycasting(t_ray *ray, t_game *game, int x)
{
    ray->camera_x = 2 * x / (double)WIDTH - 1;
    ray->ray_dir_x = game->player.dir_x + game->player.plane_x * ray->camera_x;
    ray->ray_dir_y = game->player.dir_y + game->player.plane_y * ray->camera_x;
    ray->map_x = (int)game->player.x;
    ray->map_y = (int)game->player.y;
    ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
    ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
    ray->hit = 0;
}

/**
 * ft_calculate_step_and_side_dist - Calcula los pasos y las distancias laterales del rayo.
 * @ray: Puntero a la estructura del rayo.
 * @game: Puntero a la estructura principal del juego.
 * 
 * Determina la dirección del paso (positivo o negativo) y calcula las distancias iniciales
 * desde el jugador hasta los lados del bloque en el mapa.
 */
void	ft_calculate_step_and_side_dist(t_ray *ray, t_game *game)
{
    if (ray->ray_dir_x < 0)
    {
        ray->step_x = -1;
        ray->side_dist_x = (game->player.x - ray->map_x) * ray->delta_dist_x;
    }
    else
    {
        ray->step_x = 1;
        ray->side_dist_x = (ray->map_x + 1.0 - game->player.x) * ray->delta_dist_x;
    }
    if (ray->ray_dir_y < 0)
    {
        ray->step_y = -1;
        ray->side_dist_y = (game->player.y - ray->map_y) * ray->delta_dist_y;
    }
    else
    {
        ray->step_y = 1;
        ray->side_dist_y = (ray->map_y + 1.0 - game->player.y) * ray->delta_dist_y;
    }
}

/**
 * ft_perform_dda - Realiza el algoritmo Digital Differential Analyzer (DDA).
 * @ray: Puntero a la estructura del rayo.
 * @game: Puntero a la estructura principal del juego.
 * 
 * Avanza el rayo en el mapa hasta que golpea una pared. Actualiza las distancias laterales
 * y las posiciones en el mapa en cada paso.
 */
void	ft_perform_dda(t_ray *ray, t_game *game)
{
    while (ray->hit == 0)
    {
        if (ray->side_dist_x < ray->side_dist_y)
        {
            ray->side_dist_x += ray->delta_dist_x;
            ray->map_x += ray->step_x;
            ray->side = 0;
        }
        else
        {
            ray->side_dist_y += ray->delta_dist_y;
            ray->map_y += ray->step_y;
            ray->side = 1;
        }
        if (game->data.map_data[ray->map_y][ray->map_x] == '1')
            ray->hit = 1;
    }
}

/**
 * ft_
calculate_wall_distance - Calcula la distancia perpendicular desde el jugador a la pared.
 * @ray: Puntero a la estructura del rayo.
 * @game: Puntero a la estructura principal del juego.
 * 
 * Determina la distancia perpendicular a la pared que el rayo ha golpeado,
 * utilizando la posición del jugador y los pasos del rayo.
 */
void	ft_calculate_wall_distance(t_ray *ray, t_game *game)
{
    if (ray->side == 0)
        ray->perp_wall_dist = (ray->map_x - game->player.x + (1 - ray->step_x) / 2) / ray->ray_dir_x;
    else
        ray->perp_wall_dist = (ray->map_y - game->player.y + (1 - ray->step_y) / 2) / ray->ray_dir_y;
}
