/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-tuto <lle-tuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:41:35 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/09/29 15:13:19 by lle-tuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	grooming_some_more(t_game *game)
{
	if (game->player->groom == 'W')
	{
		game->player->dirx = -1;
		game->player->diry = 0;
		game->player->planex = 0;
		game->player->planey = -0.66;
	}
	if (game->player->groom == 'E')
	{
		game->player->dirx = 1;
		game->player->diry = 0;
		game->player->planex = 0;
		game->player->planey = 0.66;
	}
}

void	grooming(t_game *game)
{
	if (game->player->groom == 'S')
	{
		game->player->dirx = 0;
		game->player->diry = 1;
		game->player->planex = -0.66;
		game->player->planey = 0;
	}
	if (game->player->groom == 'N')
	{
		game->player->dirx = 0;
		game->player->diry = -1;
		game->player->planex = 0.66;
		game->player->planey = 0;
	}
	grooming_some_more(game);
}

void	game_struct_init(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	game->textures = malloc(sizeof(t_textures));
	if (!game->textures)
		free_exit("struct malloc failed\n", game, 1);
	ft_bzero(game->textures, sizeof(t_textures));
	game->file = malloc(sizeof(t_file));
	if (!game->file)
		free_exit("struct malloc failed\n", game, 1);
	ft_bzero(game->file, sizeof(t_file));
	game->exe = malloc(sizeof(t_exe));
	if (!game->exe)
		free_exit("struct malloc failed\n", game, 1);
	ft_bzero(game->exe, sizeof(t_exe));
	game->player = malloc(sizeof(t_player));
	if (!game->player)
		free_exit("struct malloc failed\n", game, 1);
	ft_bzero(game->player, sizeof(t_player));
}
