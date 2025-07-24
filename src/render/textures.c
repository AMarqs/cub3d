#include "cub3d.h"

/**
 * ft_find_texture_path - Busca la ruta de una textura en el mapa.
 * @data: Puntero a la estructura de datos del mapa.
 * @identifier: Identificador de la textura (N, S, E, W).
 * 
 * Recorre los datos del mapa para encontrar la línea que contiene el identificador
 * y devuelve la ruta de la textura correspondiente.
 */
char	*ft_find_texture_path(t_data *data, char identifier)
{
    int	i;
    int	j;

    i = -1;
    j = 1;
    while (data->map_data[++i])
    {
        if (data->map_data[i][0] == identifier)
        {
            while (data->map_data[i][++j] <= 32)
                ;
            break ;
        }
    }
    return (ft_substr(data->map_data[i], j, ft_strlen(data->map_data[i])));
}

/**
 * ft_load_texture - Carga una textura desde un archivo PNG.
 * @game: Puntero a la estructura principal del juego.
 * @identifier: Identificador de la textura (N, S, E, W).
 * @texture: Puntero a la estructura de textura donde se almacenará la imagen.
 * 
 * Utiliza la ruta de la textura para cargarla como una imagen y la convierte
 * en una textura utilizable por MLX42. Si ocurre un error, termina el programa.
 */
void    ft_load_texture(t_game *game, char identifier, t_texture *texture)
{
    mlx_texture_t *raw_texture = NULL;
    char			*path;

    path = ft_find_texture_path(&game->data, identifier);
    raw_texture = mlx_load_png(path);
    if (!raw_texture)
    {
        fprintf(stderr, "Error\nCould not load texture: %c\n", identifier);
        free(path);
        exit(EXIT_FAILURE);
    }
    free(path);
    texture->img = mlx_texture_to_image(game->mlx, raw_texture);
    mlx_delete_texture(raw_texture);
}

/**
 * ft_load_all_textures - Carga todas las texturas necesarias para el juego.
 * @game: Puntero a la estructura principal del juego.
 * 
 * Llama a la función ft_load_texture para cargar las texturas de las paredes
 * (Norte, Sur, Este, Oeste).
 */
void    ft_load_all_textures(t_game *game)
{
    ft_load_texture(game, 'N', &game->textures.north);
    ft_load_texture(game, 'S', &game->textures.south);
    ft_load_texture(game, 'E', &game->textures.east);
    ft_load_texture(game, 'W', &game->textures.west);
}
