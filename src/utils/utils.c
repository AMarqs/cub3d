#include "cub3d.h"

/**
 * ft_close_with_error - Cierra el programa mostrando un error.
 * @data: Puntero a la estructura de datos del mapa.
 * 
 * Libera los recursos del mapa y termina el programa con un código de error.
 */
void	ft_close_with_error(t_data *data)
{
    free_map_resources(data);
    exit(EXIT_FAILURE);
}

/**
 * copy_matrix - Copia una matriz de cadenas.
 * @src: Puntero a la matriz de cadenas fuente.
 * 
 * Crea una copia de la matriz de cadenas especificada y la devuelve.
 * Si ocurre un error, devuelve NULL.
 */
char	**copy_matrix(char **src)
{
    char	**dst;
    int		i;

    i = 0;
    if (!src || !src[i])
        return (NULL);
    while (src[i])
        i++;
    dst = malloc(sizeof(char *) * (i + 1));
    i = 0;
    while (src[i])
    {
        dst[i] = ft_strdup(src[i]);
        i++;
    }
    dst[i] = NULL;
    return (dst);
}

/**
 * ft_is_whitespace - Verifica si un carácter es un espacio en blanco.
 * @str: Cadena de caracteres.
 * @index: Índice del carácter a verificar.
 * 
 * Devuelve 1 si el carácter es un espacio en blanco, de lo contrario devuelve 0.
 */
int	ft_is_whitespace(const char *str, int index)
{
    if ((str[index] >= 9 && str[index] <= 13) || str[index] == 32)
        return (1);
    return (0);
}

/**
 * ft_is_digit - Verifica si un carácter es un dígito.
 * @c: Carácter a verificar.
 * 
 * Devuelve 1 si el carácter es un dígito, de lo contrario devuelve 0.
 */
int	ft_is_digit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

/**
 * ft_string_to_int - Convierte una cadena en un entero.
 * @str: Cadena de caracteres que representa un número.
 * 
 * Convierte la cadena especificada en un número entero, manejando espacios en blanco
 * y signos (+/-). Devuelve el número convertido.
 */
int	ft_string_to_int(const char *str)
{
    size_t	index;
    int		number;
    int		sign;

    index = 0;
    number = 0;
    sign = 1;
    while (ft_is_whitespace(str, index))
        index++;
    if (str[index] == '-' || str[index] == '+')
    {
        if (str[index] == '-')
            sign = -1;
        index++;
    }
    while (ft_is_digit(str[index]))
    {
        number = number * 10 + (str[index] - '0');
        index++;
    }
    number = sign * number;
    return (number);
}
