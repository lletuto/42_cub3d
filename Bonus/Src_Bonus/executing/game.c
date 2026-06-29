/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-tuto <lle-tuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:12:55 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/09/30 14:59:25 by lle-tuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static t_img	*which_wall(t_game *game, t_math *math, t_wall *wall)
{
	wall->side = 'Z';
	if (math->side == 0)
	{
		if (math->raydirx > 0)
			return (game->textures->we);
		else
		{
			wall->side = 'A';
			return (game->textures->ea);
		}
	}
	else
	{
		if (math->raydiry > 0)
		{
			wall->side = 'A';
			return (game->textures->no);
		}
		else
			return (game->textures->so);
	}
}

void	draw_game(t_game *game)
{
	double	pointx;
	t_math	math;
	t_wall	wall;

	ft_bzero(&wall, sizeof(t_wall));
	while (wall.x_screen < game->exe->img->width)
	{
		pointx = 2.0 * wall.x_screen / (double)game->exe->img->width - 1.0;
		math = create_raydir(game, pointx, 0, 0);
		wall.line_height = (int)(game->exe->img->height / math.ray_len);
		wall.start = -wall.line_height / 2 + game->exe->img->height / 2;
		wall.end = wall.line_height / 2 + game->exe->img->height / 2;
		if (wall.start < 0)
			wall.start = 0;
		if (wall.end >= game->exe->img->height)
			wall.end = game->exe->img->height - 1;
		draw_texture(game, which_wall(game, &math, &wall), &math, &wall);
		wall.x_screen++;
	}
}
