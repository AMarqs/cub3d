#include "cub3d.h"

/**
 * ft_move_player_forward - Mueve al jugador hacia adelante.
 * @game: Puntero a la estructura principal del juego.
 * @speed: Velocidad de movimiento del jugador.
 * 
 * Calcula la nueva posición del jugador en la dirección hacia adelante
 * y actualiza su posición si no hay una pared en el camino.
 */
static void	ft_move_player_forward(t_game *game, double speed)
{
    double	new_x;
    double	new_y;

    new_x = game->player.x + game->player.dir_x * speed;
    new_y = game->player.y + game->player.dir_y * speed;
    if (!is_wall(&game->data, game->player.x, new_y))
        game->player.y = new_y;
    if (!is_wall(&game->data, new_x, game->player.y))
        game->player.x = new_x;
}

/**
 * ft_move_player_left - Mueve al jugador hacia la izquierda.
 * @game: Puntero a la estructura principal del juego.
 * @speed: Velocidad de movimiento del jugador.
 * 
 * Calcula la nueva posición del jugador en la dirección hacia la izquierda
 * y actualiza su posición si no hay una pared en el camino.
 */
static void	ft_move_player_left(t_game *game, double speed)
{
    double	new_x;
    double	new_y;

    new_x = game->player.x - game->player.plane_x * speed;
    new_y = game->player.y - game->player.plane_y * speed;
    if (!is_wall(&game->data, game->player.x, new_y))
        game->player.y = new_y;
    if (!is_wall(&game->data, new_x, game->player.y))
        game->player.x = new_x;
}

/**
 * ft_move_player_backward - Mueve al jugador hacia atrás.
 * @game: Puntero a la estructura principal del juego.
 * @speed: Velocidad de movimiento del jugador.
 * 
 * Calcula la nueva posición del jugador en la dirección hacia atrás
 * y actualiza su posición si no hay una pared en el camino.
 */
static void	ft_ft_move_player_backward(t_game *game, double speed)
{
    double	new_x;
    double	new_y;

    new_x = game->player.x - game->player.dir_x * speed;
    new_y = game->player.y - game->player.dir_y * speed;
    if (!is_wall(&game->data, game->player.x, new_y))
        game->player.y = new_y;
    if (!is_wall(&game->data, new_x, game->player.y))
        game->player.x = new_x;
}

/**
 * ft_move_player_right - Mueve al jugador hacia la derecha.
 * @game: Puntero a la estructura principal del juego.
 * @speed: Velocidad de movimiento del jugador.
 * 
 * Calcula la nueva posición del jugador en la dirección hacia la derecha
 * y actualiza su posición si no hay una pared en el camino.
 */
static void	ft_move_player_right(t_game *game, double speed)
{
    double	new_x;
    double	new_y;

    new_x = game->player.x + game->player.plane_x * speed;
    new_y = game->player.y + game->player.plane_y * speed;
    if (!is_wall(&game->data, game->player.x, new_y))
        game->player.y = new_y;
    if (!is_wall(&game->data, new_x, game->player.y))
        game->player.x = new_x;
}

/**
 * ft_process_player_input - Procesa las entradas del jugador y actualiza su posición.
 * @param: Puntero genérico que se castea a la estructura principal del juego.
 * 
 * Verifica las teclas presionadas (W, A, S, D, flechas izquierda/derecha)
 * y actualiza la posición o rotación del jugador en consecuencia.
 */
void	ft_process_player_input(void *param)
{
    t_game	*game;
    double	speed;

    game = (t_game *)param;
    speed = 0.05; // Velocidad de movimiento del jugador
    if (game->input.w)
        ft_move_player_forward(game, speed);
    if (game->input.a)
        ft_move_player_left(game, speed);
    if (game->input.s)
        ft_move_player_backward(game, speed);
    if (game->input.d)
        ft_move_player_right(game, speed);
    if (game->input.right)
        ft_rotate_player(&game->player, +0.05); // Rotación hacia la derecha
    if (game->input.left)
        ft_rotate_player(&game->player, -0.05); // Rotación hacia la izquierda
}
