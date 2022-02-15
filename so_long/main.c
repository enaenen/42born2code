/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 05:08:21 by wchae             #+#    #+#             */
/*   Updated: 2022/02/15 13:30:07 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *str, int fd)
{
	if (!str)
		return ;
	write(fd, str, ft_strlen(str));
}

void	error_exit(char	*str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	exit(1);
}

void	valid_ext(char	*file, char *ext)
{
	size_t i;

	i = ft_strlen(file) - ft_strlen(ext);
	printf("i == %d \n", i);
	while ( i < ft_strlen(file))
	{
		if (file[i] != *ext)
			error_exit("Map File Must Be \".ber\" \n");
		ext++;
		i++;
	}
}

void	map_parse(char *map_file)
{
	valid_ext(map_file, ".ber");
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit("mlx_init Error\n");
	game->win = mlx_new_window(game->mlx, 800, 600, "so_long");
	if (!game->win)
		error_exit("init_window Error \n");
}

int	exit_solong(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}
int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit(0);
}

int	main(int argc, char **argv)
{
	t_game game;
	init_game(&game);
	if (argc != 2)
		error_exit("Need .ber file\n");
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.win, 17, 0, &exit_solong, &game);
	mlx_loop(game.mlx);
	//map_parse(argv[1]);
}
