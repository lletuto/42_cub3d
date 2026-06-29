/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-tuto <lle-tuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:49:04 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/10/01 09:38:49 by lle-tuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*Calculates the lenght of the ray betwen lines of the grid*/
static double	dist_next_line(double rayDir)
{
	if (rayDir == 0)
		return (1e30);
	return (fabs(1.0 / rayDir));
}

/*Moves up and checks if there is a wall
Here we check if the next intersection is a vertical line -> +=stepx
if it isn't +=stepy we stop if its a wall*/
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

/*Calculates in which direction we should increase
mapx and mapy.
sidedist corresponds to the distance between the 
player and the first wall. 
checking the value of raydir enables us to know
which direction the ray is going and therefore know which
side is the closest line*/
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

/*Digital differential analyzer
Calculates the space betwen grid lines
sidedist - deltadist => sidedist is increased 
in taking the step which means that 
even if we go pass the wall, the distance of after 
the wall is counted therefore we have to substract it from sidedist
raylen -> lenght from player to wall*/
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

/*creates a ray (can print it), uses planexpoint calculated 
beforehand tat gives us an x coordinate
of the column on the screen that we need a ray to go to
line data is only used in the bonus for the minimap*/
t_math	create_raydir(t_game *game, double planexpoint, int print_ray,
		int color)
{
	t_math	math;
	t_line	line;

	math.raydirx = game->player->dirx + game->player->planex * planexpoint;
	math.raydiry = game->player->diry + game->player->planey * planexpoint;
	dda(game, &math);
	line.startx = (int)(game->player->posx * TILE_SIZE);
	line.starty = (int)(game->player->posy * TILE_SIZE);
	line.endx = (int)(line.startx + math.raydirx * math.ray_len * TILE_SIZE);
	line.endy = (int)(line.starty + math.raydiry * math.ray_len * TILE_SIZE);
	line.color = color;
	if (print_ray)
		draw_line(game, line);
	return (math);
}
