
#include "cub3D.h"

void	ft_close_with_error(t_game *game)
{
	ft_free_map(game);
	exit(EXIT_FAILURE);
}

char	**ft_cpy_matrix(char **src)
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

int	ft_is_space(const char *str, int counter)
{
	if ((str[cont] >= 9 && str[cont] <= 13) || str[cont] == 32)
		return (1);
	return (0);
}
