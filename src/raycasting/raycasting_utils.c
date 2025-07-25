
#include "cub3D.h"

void	ft_calculate_projection(t_ray	*ray)
{
	int	wall_line_height;
	int	wall_draw_start;
	int	wall_draw_end;

	wall_line_height = (int)(HEIGHT / ray->distance_to_wall);
	wall_draw_start = -wall_line_height / 2 + HEIGHT / 2;
	if (wall_draw_start < 0)
		wall_draw_start = 0;
	wall_draw_end = wall_line_height / 2 + HEIGHT / 2;
	if (wall_draw_end >= HEIGHT)
		wall_draw_end = HEIGHT - 1;
	ray->wall_draw_start = wall_draw_start;
	ray->wall_draw_end = wall_draw_end;
	ray->wall_line_height = wall_line_height;
}

uint32_t	ft_get_pixel_from_texture(mlx_image_t *img, int x, int y)
{
	int	i;

	i = (y * img->width + x) * 4;
	return (
		(img->pixels[i] << 24)
		| (img->pixels[i + 1] << 16)
		| (img->pixels[i + 2] << 8)
		| (img->pixels[i + 3])
	);
}

void	ft_draw_wall_slice_with_aux(t_game *game, t_ray *ray, int x, t_ray_aux *aux)
{
	if ((ray->side == 0 && ray->ray_x > 0)
		|| (ray->side == 1 && ray->ray_y < 0))
		aux->tex_x = aux->texture->width - aux->tex_x - 1;
	aux->y = ray->wall_draw_start;
	while (aux->y < ray->wall_draw_end)
	{
		aux->d = aux->y * 256 - HEIGHT * 128 + ray->wall_line_height * 128;
		aux->tex_y = (aux->d * aux->texture->height) / ray->wall_line_height / 256;
		aux->color = ft_get_pixel_from_texture(aux->texture,
				aux->tex_x, aux->tex_y);
		mlx_put_pixel(game->img, x, aux->y, aux->color);
		aux->y++;
	}
}

void	ft_draw_wall_slice(t_game *game, t_ray *ray, int x)
{
	t_ray_aux	aux;

	if (ray->side == 0)
	{
		if (ray->ray_x > 0)
			aux.texture = game->images.ea;
		else
			aux.texture = game->images.we;
	}
	else
	{
		if (ray->ray_y > 0)
			aux.texture = game->images.so;
		else
			aux.texture = game->images.no;
	}
	if (ray->side == 0)
		aux.wall_x = game->player.y + ray->distance_to_wall * ray->ray_y;
	else
		aux.wall_x = game->player.x + ray->distance_to_wall * ray->ray_x;
	aux.wall_x -= floor(aux.wall_x);
	aux.tex_x = (int)(aux.wall_x * (double)aux.texture->width);
	ft_draw_wall_slice_with_aux(game, ray, x, &aux);
}

void	ft_raycast_all_columns(t_game *game)
{
	int		x;
	t_ray	ray;

	x = -1;
	while (++x < WIDTH)
	{
		ft_init_ray(game, &ray, x);
		ft_calculate_steps_and_sidedist(game, &ray);
		ft_perform_dda(game, &ray);
		ft_calculate_projection(&ray);
		ft_draw_wall_slice(game, &ray, x);
	}
}
