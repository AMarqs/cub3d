#include "cub3D.h"

void	ft_init_ray(t_game *game, t_ray *ray, int x)
{
	ray->collision = 0;
	ray->plane_x = 2.0 * x / (double)WIDTH - 1.0;
	ray->ray_x = game->player.dir_x + game->player.plane_x * ray->plane_x;
	ray->ray_y = game->player.dir_y + game->player.plane_y * ray->plane_x;
	ray->map_x = (int)game->player.x;
	ray->map_y = (int)game->player.y;
	if (ray->ray_x == 0)
		ray->delta_distance_x = 1e30;
	else
		ray->delta_distance_x = 1 / ray->ray_x;
	if (ray->delta_distance_x < 0)
		ray->delta_distance_x = -ray->delta_distance_x;
	if (ray->ray_y == 0)
		ray->delta_distance_y = 1e30;
	else
		ray->delta_distance_y = 1 / ray->ray_y;
	if (ray->delta_distance_y < 0)
		ray->delta_distance_y = -ray->delta_distance_y;
}

void	ft_calculate_steps_and_sidedist(t_game *game, t_ray *ray)
{
	if (ray->ray_x < 0)
	{
		ray->step_x = -1;
		ray->side_distance_x = (game->player.x - ray->map_x) * ray->delta_distance_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_distance_x = (ray->map_x + 1 - game->player.x) * ray->delta_distance_x;
	}
	if (ray->ray_y < 0)
	{
		ray->step_y = -1;
		ray->side_distance_y = (game->player.y - ray->map_y) * ray->delta_distance_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_distance_y = (ray->map_y + 1 - game->player.y) * ray->delta_distance_y;
	}
}

void	ft_perform_dda(t_game *game, t_ray *ray)
{
	while (ray->collision == 0)
	{
		if (ray->side_distance_x < ray->side_distance_y)
		{
			ray->side_distance_x += ray->delta_distance_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_distance_y += ray->delta_distance_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (game->map[ray->map_y][ray->map_x] == '1')
			ray->collision = 1;
	}
	if (ray->side == 0)
		ray->distance_to_wall = (ray->side_distance_x - ray->delta_distance_x);
	else
		ray->distance_to_wall = (ray->side_distance_y - ray->delta_distance_y);
}
