#include "cub3D.h"

static void	move_forward(t_game *game, double speed)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x + game->player.dir_x * speed;
	new_y = game->player.y + game->player.dir_y * speed;
	if (!ft_is_wall(game, game->player.x, new_y))
		game->player.y = new_y;
	if (!ft_is_wall(game, new_x, game->player.y))
		game->player.x = new_x;
}

static void	move_left(t_game *game, double speed)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x - game->player.plane_x * speed;
	new_y = game->player.y - game->player.plane_y * speed;
	if (!ft_is_wall(game, game->player.x, new_y))
		game->player.y = new_y;
	if (!ft_is_wall(game, new_x, game->player.y))
		game->player.x = new_x;
}

static void	move_backward(t_game *game, double speed)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x - game->player.dir_x * speed;
	new_y = game->player.y - game->player.dir_y * speed;
	if (!ft_is_wall(game, game->player.x, new_y))
		game->player.y = new_y;
	if (!ft_is_wall(game, new_x, game->player.y))
		game->player.x = new_x;
}

static void	move_right(t_game *game, double speed)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x + game->player.plane_x * speed;
	new_y = game->player.y + game->player.plane_y * speed;
	if (!ft_is_wall(game, game->player.x, new_y))
		game->player.y = new_y;
	if (!ft_is_wall(game, new_x, game->player.y))
		game->player.x = new_x;
}

void	ft_handle_input(void *param)
{
	t_game	*game;
	double	speed;

	game = (t_game *)param;
	speed = game->player.move_speed;
	if (game->control.w)
		move_forward(game, speed);
	if (game->control.a)
		move_left(game, speed);
	if (game->control.s)
		move_backward(game, speed);
	if (game->control.d)
		move_right(game, speed);
	if (game->control.right)
		ft_rotate_player(&game->player, +game->player.rot_speed);
	if (game->control.left)
		ft_rotate_player(&game->player, -game->player.rot_speed);
}
