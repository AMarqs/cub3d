#include "cub3d.h"

/**
 * ft_count_map_lines - Cuenta el número de líneas en el archivo del mapa.
 * @map_path: Ruta del archivo del mapa.
 * @data: Puntero a la estructura de datos del mapa.
 * 
 * Abre el archivo del mapa y cuenta el número de líneas. Actualiza el número de filas
 * en la estructura y devuelve el número de líneas.
 */
int	ft_count_map_lines(const char *map_path, t_data *data)
{
    char	*line;
    int		line_count;
    int		fd;

    fd = open(map_path, O_RDONLY);
    if (fd == -1)
    {
        fprintf(stderr, "Error\nCould not open the file to count lines.\n");
        exit(EXIT_FAILURE);
    }
    line = get_next_line(fd);
    line_count = 0;
    while (line)
    {
        line_count++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    data->file_rows = line_count;
    return (line_count);
}

/**
 * ft_free_map_resources - Libera los recursos asociados al mapa.
 * @data: Puntero a la estructura de datos del mapa.
 * 
 * Libera la memoria asignada para los datos del mapa.
 */
void	ft_free_map(t_data *data)
{
    int	i;

    i = -1;
    if (!data)
        return ;
    if (data->map_data)
    {
        while (++i < data->file_rows && data->map_data[i])
            free(data->map_data[i]);
        free(data->map_data);
    }
}

/**
 * ft_read_map_lines - Lee las líneas del archivo del mapa y las almacena en la estructura de datos.
 * @fd: Descriptor del archivo del mapa.
 * @line: Línea actual del archivo.
 * @data: Puntero a la estructura de datos del mapa.
 * 
 * Duplica cada línea del archivo y la almacena en la estructura de datos del mapa.
 * Si ocurre un error, libera los recursos y termina el programa.
 */
void	ft_read_map_lines(int fd, char *line, t_data *data)
{
    int	i;

    i = 0;
    while (line)
    {
        if (line[0] == '\n')
            data->map_data[i] = ft_strdup("\n");
        else if (line[ft_strlen(line) - 1] == '\n')
            data->map_data[i] = ft_substr(line, 0, ft_strlen(line) - 1);
        else
            data->map_data[i] = ft_strdup(line);
        if (!data->map_data[i])
        {
            fprintf(stderr, "Error\nCould not duplicate line.\n");
            free(line);
            ft_free_map_resources(data);
            exit(EXIT_FAILURE);
        }
        free(line);
        i++;
        line = get_next_line(fd);
    }
    data->map_data[i] = NULL;
}

/**
 * ft_read_map - Lee el archivo del mapa y lo almacena en la estructura de datos.
 * @data: Puntero a la estructura de datos del mapa.
 * @argv: Argumentos de la línea de comandos.
 * 
 * Abre el archivo del mapa, cuenta las líneas, asigna memoria para los datos
 * y almacena las líneas en la estructura de datos.
 */
void	ft_read_map(t_data *data, char **argv)
{
    char	*line;
    int		fd;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        fprintf(stderr, "Error\nCould not open the file properly.\n");
        exit(EXIT_FAILURE);
    }
    data->map_data = malloc(sizeof(char *) * (ft_count_map_lines(argv[1], data) + 1));
    if (!data->map_data)
    {
        fprintf(stderr, "Error\nCould not allocate memory for the map data.\n");
        exit(EXIT_FAILURE);
    }
    line = get_next_line(fd);
    if (!line)
    {
        fprintf(stderr, "Error\nThe map is empty.\n");
        ft_free_map_resources(data);
        exit(EXIT_FAILURE);
    }
    ft_read_map_lines(fd, line, data);
    close(fd);
}

/**
 * ft_validate_map_name - Valida que el nombre del archivo del mapa termine en ".cub".
 * @argv: Argumentos de la línea de comandos.
 * 
 * Verifica que el nombre del archivo del mapa tenga la extensión ".cub".
 * Si no es válido, muestra un error y termina el programa.
 */
void	ft_validate_map_name(char **argv)
{
    int	len;

    len = ft_strlen(argv[1]);
    if (argv[1][len - 1] != 'b' || argv[1][len - 2] != 'u'
        || argv[1][len - 3] != 'c' || argv[1][len - 4] != '.')
    {
        fprintf(stderr, "Error\nThe map must end with .cub.\n");
        exit(EXIT_FAILURE);
    }
}
