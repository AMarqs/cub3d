#include "cub3d.h"

/**
 * ft_initialize_graphics - Inicializa la biblioteca gráfica MLX42.
 * @game: Puntero a la estructura principal del juego.
 * 
 * Configura la ventana, la imagen y otros recursos gráficos necesarios para el juego.
 * Si ocurre un error durante la inicialización, muestra un mensaje y termina el programa.
 */
void	ft_initialize_graphics(t_game *game)
{
    mlx_set_setting(MLX_STRETCH_IMAGE, true);
    game->mlx = mlx_init(WIDTH, HEIGHT, TITLE, true);
    if (!game->mlx)
    {
        fprintf(stderr, "Error:\nCould not initialize MLX42");
        exit(EXIT_FAILURE);
    }
    game->window = mlx_new_image(game->mlx, WIDTH, HEIGHT);
    if (!game->window)
    {
        fprintf(stderr, "Error:\nCould not create window");
        exit(EXIT_FAILURE);
    }
    mlx_image_to_window(game->mlx, game->window, 0, 0);
}

/**
 * set_player_direction - Configura la dirección inicial del jugador.
 * @game: Puntero a la estructura principal del juego.
 * @x: Coordenada X del jugador en el mapa.
 * @y: Coordenada Y del jugador en el mapa.
 * 
 * Ajusta la posición del jugador según su orientación inicial en el mapa.
 */
void	set_player_direction(t_game *game, int x, int y)
{
    game->player.x = x + 0.5;
    game->player.y = y + 0.5;
}

/**
 * initialize_player_position - Busca y configura la posición inicial del jugador en el mapa.
 * @game: Puntero a la estructura principal del juego.
 * 
 * Recorre el mapa para encontrar la posición inicial del jugador y la configura.
 * Si no se encuentra una posición válida, el programa termina con un error.
 */
void	initialize_player_position(t_game *game)
{
    int	x;
    int	y;

    y = 0;
    while (game->data.map_data[y])
    {
        x = 0;
        while (game->data.map_data[y][x])
        {
            if (game->data.map_data[y][x] == 'N' || game->data.map_data[y][x] == 'S'
                || game->data.map_data[y][x] == 'E' || game->data.map_data[y][x] == 'W')
            {
                set_player_direction(game, x, y);
                return ;
            }
            x++;
        }
        y++;
    }
    fprintf(stderr, "Error\nPlayer start position not found.\n");
    exit(EXIT_FAILURE);
}

/**
 * load_textures - Carga las texturas desde las rutas especificadas en el archivo .cub.
 * @game: Puntero a la estructura principal del juego.
 * 
 * Utiliza las rutas de las texturas almacenadas en la estructura t_data para cargar
 * las texturas en la estructura t_texture.
 */
void	load_textures(t_game *game)
{
    mlx_texture_t	*raw;

    raw = mlx_load_png(game->data.no_texture);
    if (!raw)
    {
        fprintf(stderr, "Error\nCould not load north texture.\n");
        exit(EXIT_FAILURE);
    }
    game->textures.north.img = mlx_texture_to_image(game->mlx, raw);
    mlx_delete_texture(raw);

    raw = mlx_load_png(game->data.so_texture);
    if (!raw)
    {
        fprintf(stderr, "Error\nCould not load south texture.\n");
        exit(EXIT_FAILURE);
    }
    game->textures.south.img = mlx_texture_to_image(game->mlx, raw);
    mlx_delete_texture(raw);

    raw = mlx_load_png(game->data.we_texture);
    if (!raw)
    {
        fprintf(stderr, "Error\nCould not load west texture.\n");
        exit(EXIT_FAILURE);
    }
    game->textures.west.img = mlx_texture_to_image(game->mlx, raw);
    mlx_delete_texture(raw);

    raw = mlx_load_png(game->data.ea_texture);
    if (!raw)
    {
        fprintf(stderr, "Error\nCould not load east texture.\n");
        exit(EXIT_FAILURE);
    }
    game->textures.east.img = mlx_texture_to_image(game->mlx, raw);
    mlx_delete_texture(raw);
}

void    ft_init(t_game *game)
{
    ft_initialize_graphics(game);
    ft_initialize_player_position(game);
    ft_load_textures(game);
    game->player.angle = 0; // Inicializa el ángulo del jugador
    game->player.speed = 0.1; // Velocidad de movimiento del jugador
    game->player.rotation_speed = 0.05; // Velocidad de rotación del jugador
}
