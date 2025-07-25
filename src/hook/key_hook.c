#include "cub3d.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
    t_game	*game;

    game = (t_game *)param;
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
        mlx_close_window(game->mlx);
    if (keydata.key == MLX_KEY_W)
        game->control.w = (keydata.action != MLX_RELEASE);
    if (keydata.key == MLX_KEY_S)
        game->control.s = (keydata.action != MLX_RELEASE);
    if (keydata.key == MLX_KEY_A)
        game->control.a = (keydata.action != MLX_RELEASE);
    if (keydata.key == MLX_KEY_D)
        game->control.d = (keydata.action != MLX_RELEASE);
    if (keydata.key == MLX_KEY_LEFT)
        game->control.left = (keydata.action != MLX_RELEASE);
    if (keydata.key == MLX_KEY_RIGHT)
        game->control.right = (keydata.action != MLX_RELEASE);
}
