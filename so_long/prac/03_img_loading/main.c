#include <stdio.h>
#include <stdlib.h>
#include "../mlx/mlx.h"

#define	X_EVENT_KEY_EXIT	17
#define	X_EVENT_KEY_PRESS	2
#define	KEY_ESC			53

int	ft_exit(int keycode)
{
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*win;
	void	*img;

	int	img_width;
	int	img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "mlx_img_test");
	img = mlx_xpm_file_to_image(mlx, "../textures/wall_test.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 50, 50);
	mlx_hook(win, X_EVENT_KEY_PRESS, 0, &ft_exit, 0);
	mlx_loop(mlx);

	return (0);
}
