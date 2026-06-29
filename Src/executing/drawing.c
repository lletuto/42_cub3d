/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-tuto <lle-tuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:40:56 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/09/24 16:48:41 by lle-tuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	my_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= game->exe->img->width
		|| y >= game->exe->img->height)
		return ;
	dst = game->exe->img->addr + (y * game->exe->img->line_length + x
			* (game->exe->img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_square(t_game *game, int x, int y, int color)
{
	int	dy;
	int	dx;

	dy = 0;
	while (dy < TILE_SIZE)
	{
		dx = 0;
		while (dx < TILE_SIZE)
		{
			my_pixel_put(game, x + dx, y + dy, color);
			dx++;
		}
		dy++;
	}
}

static void	actually_drawing_now(t_game *game, int dx, int dy, t_line line)
{
	int		steps;
	float	x;
	float	y;
	int		i;

	i = 0;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	x = line.startx;
	y = line.starty;
	while (i <= steps)
	{
		my_pixel_put(game, (int)x, (int)y, line.color);
		x += dx / (float)steps;
		y += dy / (float)steps;
		i++;
	}
}

void	draw_line(t_game *game, t_line line)
{
	int	dx;
	int	dy;

	dx = line.endx - line.startx;
	dy = line.endy - line.starty;
	actually_drawing_now(game, dx, dy, line);
}

void	draw_player(t_game *game)
{
	float	px;
	float	py;
	int		dy;
	int		dx;

	dy = -2;
	px = (game->player->posx) * TILE_SIZE;
	py = (game->player->posy) * TILE_SIZE;
	while (dy <= 2)
	{
		dx = -2;
		while (dx <= 2)
		{
			my_pixel_put(game, (int)px + dx, (int)py + dy, 0x00ffff);
			dx++;
		}
		dy++;
	}
}
