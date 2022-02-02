#include "./mlx/mlx.h"
#include <stdio.h>

typedef struct s_data{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}           t_data;

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

int main(void)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 800, 600, "mlx_42?");
    img.img = mlx_new_image(mlx_win, 800, 600);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    for (int i=0; i<300; i++){
     my_mlx_pixel_put(&img, i, i, 0xABCDEF);
     my_mlx_pixel_put(&img, 5, i, 0xABCDEF);
     my_mlx_pixel_put(&img, i, 5, 0xABCDEF);
    }
    printf("%d\n", img.endian);
    printf("%s\n", img.addr);
    printf("%d\n", img.bits_per_pixel);
    printf("%d\n", img.line_length);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}
