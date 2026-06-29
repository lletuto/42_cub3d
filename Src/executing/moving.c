/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaudrez <elaudrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:49:59 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/09/26 16:00:44 by elaudrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	rotate(t_game *game, double rotspeed)
{
	double	olddirx;
	double	oldplanex;

	olddirx = game->player->dirx;
	game->player->dirx = game->player->dirx * cos(rotspeed) - game->player->diry
		* sin(rotspeed);
	game->player->diry = olddirx * sin(rotspeed) + game->player->diry
		* cos(rotspeed);
	oldplanex = game->player->planex;
	game->player->planex = game->player->planex * cos(rotspeed)
		- game->player->planey * sin(rotspeed);
	game->player->planey = oldplanex * sin(rotspeed) + game->player->planey
		* cos(rotspeed);
}

int	is_wall(t_game *game, float x, float y)
{
	if (game->file->map_matrix[(int)y][(int)x] == '1')
		return (1);
	return (0);
}

int	can_move(t_game *game, float newx, float newy)
{
	if (is_wall(game, newx - COLLAPSE, newy - COLLAPSE))
		return (0);
	if (is_wall(game, newx + COLLAPSE, newy - COLLAPSE))
		return (0);
	if (is_wall(game, newx - COLLAPSE, newy + COLLAPSE))
		return (0);
	if (is_wall(game, newx + COLLAPSE, newy + COLLAPSE))
		return (0);
	return (1);
}

static void	moving_more(t_game *game, int clue, float *newx, float *newy)
{
	if (clue == 4)
	{
		*newx += (game->player->planex * MOVE_SPEED);
		*newy += (game->player->planey * MOVE_SPEED);
	}
	else if (clue == 3)
	{
		*newx -= (game->player->planex * MOVE_SPEED);
		*newy -= (game->player->planey * MOVE_SPEED);
	}
}

void	moving(t_game *game, int clue)
{
	float	newx;
	float	newy;

	newx = game->player->posx;
	newy = game->player->posy;
	if (clue == 1)
	{
		newx += (game->player->dirx * MOVE_SPEED);
		newy += (game->player->diry * MOVE_SPEED);
	}
	else if (clue == 2)
	{
		newx -= (game->player->dirx * MOVE_SPEED);
		newy -= (game->player->diry * MOVE_SPEED);
	}
	moving_more(game, clue, &newx, &newy);
	if (can_move(game, newx, newy))
	{
		game->player->posx = newx;
		game->player->posy = newy;
	}
}
