#include "cub3d.h"

/**
 * key_hook - Maneja las entradas del teclado.
 * @keydata: Datos de la tecla presionada.
 * @param: Puntero a la estructura principal del juego.
 * 
 * Actualiza el estado de las teclas en la estructura de entrada del juego
 * y cierra la ventana si se presiona la tecla Escape.
 */
void	key_hook(mlx_key_data_t keydata, void *param)
{
    t_game	*game;

    game = (t_game *)param;
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
        mlx_close_window(game->mlx);
    if (keydata.key == MLX_KEY_W)
        game->input.w = (keydata.action != MLX_RELEASE);
    if (keydata.key == MLX_KEY_S)
        game->input.s = (keydata.action != MLX_RELEASE);
    if (keydata.key == MLX_KEY_A)
        game->input.a = (keydata.action != MLX_RELEASE);
    if (keydata.key == MLX_KEY_D)
        game->input.d = (keydata.action != MLX_RELEASE);
    if (keydata.key == MLX_KEY_LEFT)
        game->input.left = (keydata.action != MLX_RELEASE);
    if (keydata.key == MLX_KEY_RIGHT)
        game->input.right = (keydata.action != MLX_RELEASE);
}
