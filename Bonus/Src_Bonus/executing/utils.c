/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-tuto <lle-tuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:19:32 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/09/30 13:54:04 by lle-tuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	mouse_handler(int x, int y, t_game *game)
{
	int	posx;
	int	center_x;
	int	center_y;

	center_x = game->exe->img->width / 2;
	center_y = game->exe->img->height / 2;
	mlx_mouse_get_pos(game->exe->mlx, game->exe->win, &x, &y);
	posx = x - game->oldx;
	if (posx != 0)
		rotate(game, posx * (ROTSPEED) * 0.05);
	if (x < 50 || x > game->exe->img->width - 50)
	{
		mlx_mouse_move(game->exe->mlx, game->exe->win, center_x, center_y);
		game->oldx = center_x;
	}
	else
		game->oldx = x;
	return (0);
}

int	key_handler(int keycode, t_game *game)
{
	if (keycode == 65307)
		free_exit(NULL, game, 2);
	if (keycode == 119)
		moving(game, 1);
	if (keycode == 115)
		moving(game, 2);
	if (keycode == 97)
		moving(game, 3);
	if (keycode == 100)
		moving(game, 4);
	if (keycode == 65361)
		rotate(game, -ROTSPEED);
	if (keycode == 65363)
		rotate(game, +ROTSPEED);
	return (0);
}

int	closing(t_game *game)
{
	free_exit(NULL, game, 0);
	return (0);
}
