#include "cub3d.h"

/**
 * ft_initialize_map - Inicializa los valores básicos del mapa.
 * @map: Puntero a la estructura del mapa.
 * 
 * Configura los valores iniciales del mapa, como los colores del suelo y techo.
 */
void	ft_initialize_map(t_map *map)
{
    if (!map)
    {
        fprintf(stderr, "Error\nCould not allocate the map");
        exit(EXIT_FAILURE);
    }
    map->floor.r = 0;
    map->floor.g = 0;
    map->floor.b = 0;
    map->ceiling.r = 0;
    map->ceiling.g = 0;
    map->ceiling.b = 0;
}

/**
 * validate_elements_count - Valida que cada elemento del mapa esté definido una sola vez.
 * @data: Puntero a la estructura de datos del mapa.
 * 
 * Verifica que cada textura y color esté definido correctamente.
 * Si hay duplicados o faltantes, muestra un error y termina el programa.
 */
void	ft_validate_elements_count(t_data *data)
{
    if (!data->no_texture || !data->so_texture || !data->we_texture || !data->ea_texture)
    {
        fprintf(stderr, "Error\nYou must specify all textures (N, S, E, W).\n");
        exit(EXIT_FAILURE);
    }
    if (data->floor.r == -1 || data->ceiling.r == -1)
    {
        fprintf(stderr, "Error\nYou must specify both floor and ceiling colors.\n");
        exit(EXIT_FAILURE);
    }
}

/**
 * count_element_occurrences - Extrae los elementos del mapa y los almacena en la estructura de datos.
 * @data: Puntero a la estructura de datos del mapa.
 * @line: Línea actual del archivo del mapa.
 * 
 * Extrae las rutas de las texturas y los colores del suelo y techo desde las líneas del archivo.
 */
void	ft_count_element_occurrences(t_data *data, char *line)
{
    if (line[0] == 'N' && !data->no_texture)
        data->no_texture = ft_strdup(line + 2);
    else if (line[0] == 'S' && !data->so_texture)
        data->so_texture = ft_strdup(line + 2);
    else if (line[0] == 'W' && !data->we_texture)
        data->we_texture = ft_strdup(line + 2);
    else if (line[0] == 'E' && !data->ea_texture)
        data->ea_texture = ft_strdup(line + 2);
    else if (line[0] == 'F')
        sscanf(line + 2, "%d,%d,%d", &data->floor.r, &data->floor.g, &data->floor.b);
    else if (line[0] == 'C')
        sscanf(line + 2, "%d,%d,%d", &data->ceiling.r, &data->ceiling.g, &data->ceiling.b);
    else
    {
        fprintf(stderr, "Error\nInvalid element in map file: %s\n", line);
        exit(EXIT_FAILURE);
    }
}
