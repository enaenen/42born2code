/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_tutorial.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 20:50:05 by wchae             #+#    #+#             */
/*   Updated: 2022/02/02 20:50:16 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"

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
    int i;
    int j;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 800, 600, "mlx_42?");
    img.img = mlx_new_image(mlx_win, 800, 600);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    i =0;
    j =0;
    while (i < 799)
    {
	    my_mlx_pixel_put(&img, i, 0, 0x00FF0000);
	    my_mlx_pixel_put(&img, i, 599, 0x00FF0000);
	    i++;
    }
    while (j < 599)
    {
	    my_mlx_pixel_put(&img, 0, j, 0x00FF0000);
	    my_mlx_pixel_put(&img, i, j, 0x00FF0000);
	    j++;
    }
   /* for (int i=0; i<500; i++){
     my_mlx_pixel_put(&img, i, i, 0x00FF0000);
     my_mlx_pixel_put(&img, 5, i, 0x00FF0000);
     my_mlx_pixel_put(&img, i, 5, 0x00FF0000);
    }
    */
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}
