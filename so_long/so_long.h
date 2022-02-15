/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:00:01 by wchae             #+#    #+#             */
/*   Updated: 2022/02/15 13:30:40 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx/mlx.h"

# include <stdio.h>

#define X_EVENT_KEY_PRESS	2

# define TRUE			1
# define FALSE			0

# define KEY_ESC		53

typedef struct s_game
{
	void	*mlx;
	void	*win;
}		t_game;

#endif
