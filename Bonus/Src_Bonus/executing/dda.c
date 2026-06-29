/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-tuto <lle-tuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:49:04 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/09/24 16:48:41 by lle-tuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static double	dist_next_line(double rayDir)
{
	if (rayDir == 0)
		return (1e30);
	return (fabs(1.0 / rayDir));
}

static int	taking_the_step(t_game *game, t_math *math)
{
	int	wall;

	wall = 0;
	while (!wall && game->file->map_matrix[math->mapy])
	{
		if (math->sidedistx < math->sidedisty)
		{
			math->sidedistx += math->deltadistx;
			if (game->file->map_matrix[math->mapy][math->mapx + math->stepx])
				math->mapx += math->stepx;
			math->side = 0;
		}
		else
		{
			math->sidedisty += math->deltadisty;
			if (game->file->map_matrix[math->mapy + math->stepy])
				math->mapy += math->stepy;
			math->side = 1;
		}
		if (game->file->map_matrix[math->mapy][math->mapx] == '1')
			wall = 1;
	}
	return (math->side);
}

static void	stepping_up(t_game *game, t_math *math)
{
	if (math->raydirx < 0)
	{
		math->stepx = -1;
		math->sidedistx = (game->player->posx - math->mapx) * math->deltadistx;
	}
	else
	{
		math->stepx = 1;
		math->sidedistx = (math->mapx + 1.0 - game->player->posx)
			* math->deltadistx;
	}
	if (math->raydiry < 0)
	{
		math->stepy = -1;
		math->sidedisty = (game->player->posy - math->mapy) * math->deltadisty;
	}
	else
	{
		math->stepy = 1;
		math->sidedisty = (math->mapy + 1.0 - game->player->posy)
			* math->deltadisty;
	}
}

void	dda(t_game *game, t_math *math)
{
	int	side;

	math->deltadistx = dist_next_line(math->raydirx);
	math->deltadisty = dist_next_line(math->raydiry);
	math->mapx = (int)game->player->posx;
	math->mapy = (int)game->player->posy;
	stepping_up(game, math);
	side = taking_the_step(game, math);
	if (side == 0)
		math->ray_len = math->sidedistx - math->deltadistx;
	else
		math->ray_len = math->sidedisty - math->deltadisty;
}
