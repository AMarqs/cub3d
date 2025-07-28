#include "cub3d.h"

uint32_t mlx_get_pixel(t_img *img, int x, int y)
{
    return ((uint32_t *)(img->data))[y * img->width + x];
}
