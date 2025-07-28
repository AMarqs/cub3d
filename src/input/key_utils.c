#include "cub3d.h"

/**
 * ft_rotate_player - Rota al jugador en la dirección especificada.
 * @player: Puntero a la estructura del jugador.
 * @direction: Dirección de rotación (positiva para derecha, negativa para izquierda).
 * 
 * Calcula la nueva dirección del jugador utilizando trigonometría
 * para realizar la rotación.
 */
void	ft_rotate_player(t_player *player, double direction)
{
    double	old_dir_x;
    double	rotation_angle;

    old_dir_x = player->dir_x;
    rotation_angle = direction;
    player->dir_x = player->dir_x * cos(rotation_angle) - player->dir_y * sin(rotation_angle);
    player->dir_y = old_dir_x * sin(rotation_angle) + player->dir_y * cos(rotation_angle);
}

/**
 * ft_is_wall - Verifica si una posición en el mapa es una pared.
 * @data: Puntero a la estructura de datos del mapa.
 * @x: Coordenada X en el mapa.
 * @y: Coordenada Y en el mapa.
 * 
 * Devuelve 1 si la posición especificada contiene una pared,
 * de lo contrario devuelve 0.
 */
int	ft_is_wall(t_data *data, double x, double y)
{
    return (
        data->map_data[(int)(y)][(int)(x)] == '1' ||
        data->map_data[(int)(y + COLLISION_MARGIN)][(int)(x)] == '1' ||
        data->map_data[(int)(y - COLLISION_MARGIN)][(int)(x)] == '1' ||
        data->map_data[(int)(y)][(int)(x + COLLISION_MARGIN)] == '1' ||
        data->map_data[(int)(y)][(int)(x - COLLISION_MARGIN)] == '1' ||
        data->map_data[(int)(y + COLLISION_MARGIN)]
            [(int)(x + COLLISION_MARGIN)] == '1' ||
        data->map_data[(int)(y - COLLISION_MARGIN)]
            [(int)(x - COLLISION_MARGIN)] == '1'
    );
}
