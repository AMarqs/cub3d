#include "cub3d.h"

/**
 * ft_draw_background - Dibuja el fondo de la pantalla.
 * @game: Puntero a la estructura principal del juego.
 * 
 * Rellena la mitad superior de la pantalla con el color del techo y la mitad inferior
 * con el color del suelo, utilizando los valores definidos en la estructura del mapa.
 */
void	ft_draw_background(t_game *game)
{
    uint32_t	ceiling_color;
    uint32_t	floor_color;
    int			x;
    int			y;

    ceiling_color = (game->map.ceiling.r << 24) | (game->map.ceiling.g << 16)
        | (game->map.ceiling.b << 8) | 255;
    floor_color = (game->map.floor.r << 24) | (game->map.floor.g << 16)
        | (game->map.floor.b << 8) | 255;
    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            if (y < HEIGHT / 2)
                mlx_put_pixel(game->window, x, y, ceiling_color);
            else
                mlx_put_pixel(game->window, x, y, floor_color);
            x++;
        }
        y++;
    }
}

/**
 * ft_draw_vertical_line - Dibuja una línea vertical en la pantalla.
 * @window: Puntero a la ventana donde se dibujará la línea.
 * @line: Estructura que contiene las coordenadas y el color de la línea.
 * 
 * Dibuja una línea vertical en la ventana especificada, verificando que las coordenadas
 * estén dentro de los límites de la pantalla.
 */
void	ft_draw_vertical_line(void *window, t_line line)
{
    int	y;

    if (!window)
        return ;
    y = line.start_y;
    while (y <= line.end_y)
    {
        if (y >= 0 && y < HEIGHT && line.x >= 0 && line.x < WIDTH)
            mlx_put_pixel(window, line.x, y, line.color);
        y++;
    }
}

/**
 * ft_draw_column - Dibuja una columna en la pantalla.
 * @game: Puntero a la estructura principal del juego.
 * @column: Índice de la columna actual en la pantalla.
 * @start: Coordenada Y inicial de la columna.
 * @end: Coordenada Y final de la columna.
 * 
 * Crea una estructura de línea con las coordenadas y el color especificados,
 * y la dibuja en la ventana del juego.
 */
void	ft_draw_column(t_game *game, int column, int start, int end)
{
    t_line	line;

    line.x = column;
    line.start_y = start;
    line.end_y = end;
    line.color = 0xFFFFFFFF;
    ft_draw_vertical_line(game->window, line);
}

/**
 * ft_update_game - Actualiza el estado del juego y renderiza la pantalla.
 * @param: Puntero genérico que se castea a la estructura principal del juego.
 * 
 * Procesa las entradas del jugador, dibuja el fondo y realiza el raycasting
 * para renderizar las paredes en la pantalla.
 */
void	ft_update_game(void *param)
{
    t_game	*game;

    game = (t_game *)param;
    ft_process_player_input(game);
    ft_draw_background(game);
    ft_raycast_all_columns(game);
}
