/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-tuto <lle-tuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:38:07 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/09/30 10:40:02 by lle-tuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	player_finder(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->file->map_matrix[y])
	{
		x = 0;
		while (game->file->map_matrix[y][x])
		{
			if (is_character_tile(game->file->map_matrix[y][x]))
			{
				game->player->posx = x + 0.5;
				game->player->posy = y + 0.5;
				return ;
			}
			x++;
		}
		y++;
	}
}

static int	is_ok_tile(char c)
{
	if (c == '1' || c == '0' || is_character_tile(c))
		return (1);
	return (0);
}

static void	wall_check(t_game *game, int i, int j)
{
	if (i == 0 || i == game->file->m_size - 1)
		free_exit("Error\nUp or down wall error or unauthorised space\n", game,
			2);
	if (i > 0 && j > (int)ft_strlen(game->file->map_matrix[i - 1]))
		free_exit("Error\nUp wall error or unauthorised space\n", game, 2);
	if (i > 0 && j <= (int)ft_strlen(game->file->map_matrix[i - 1])
		&& !is_ok_tile(game->file->map_matrix[i - 1][j]))
		free_exit("Error\nUp wall error or unauthorised space\n", game, 2);
	if (((i + 1) < game->file->m_size
			&& j <= (int)ft_strlen(game->file->map_matrix[i + 1])
			&& !is_ok_tile(game->file->map_matrix[i + 1][j]))
		|| !game->file->map_matrix[i + 1][j])
		free_exit("Error\nDown wall error or unauthorised space\n", game, 2);
	if ((j > 0 && !is_ok_tile(game->file->map_matrix[i][j - 1])) || j == 0)
		free_exit("Error\nLeft wall error or unauthorised space\n", game, 2);
	if ((j + 1 < (int)ft_strlen(game->file->map_matrix[i])
			&& !is_ok_tile(game->file->map_matrix[i][j + 1]))
		|| !game->file->map_matrix[i][j + 1])
		free_exit("Error\nRight wall error or unauthorised space\n", game, 2);
}

void	i_hate_the_norm(t_game *game, char tile, int *c_tiles)
{
	game->player->groom = tile;
	(*c_tiles)++;
}

void	map_checking(t_game *game)
{
	int	i;
	int	j;
	int	c_tiles;

	j = 0;
	i = 0;
	c_tiles = 0;
	while (game->file->map_matrix[i])
	{
		j = 0;
		while (game->file->map_matrix[i][j])
		{
			if (game->file->map_matrix[i][j] == '0'
				|| is_character_tile(game->file->map_matrix[i][j]))
				wall_check(game, i, j);
			if (is_character_tile(game->file->map_matrix[i][j]))
				i_hate_the_norm(game, game->file->map_matrix[i][j], &c_tiles);
			j++;
		}
		i++;
	}
	if (c_tiles != 1)
		free_exit("Error\nI only need one player and it's you\n", game, 2);
	player_finder(game);
}
