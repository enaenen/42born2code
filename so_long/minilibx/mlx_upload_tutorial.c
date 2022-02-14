/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_upload_tutorial.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:51:30 by wchae             #+#    #+#             */
/*   Updated: 2022/02/03 16:53:04 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdio.h>

int main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int	width;
	int	height;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1280, 720,"image load");
	img_ptr = mlx_xpm_file_to_image(mlx_ptr, "texture/wall.xpm", &width, &height);
	printf("width = %d , height = %d \n", width, height);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}
