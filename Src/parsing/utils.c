/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaudrez <elaudrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:11:30 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/09/29 11:52:13 by elaudrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '	' && line[i] != '\n'
			&& line[i] != '\r')
			return (0);
		i++;
	}
	return (1);
}

int	is_character_tile(char letter)
{
	if (letter == 'N' || letter == 'S' || letter == 'E' || letter == 'W')
		return (1);
	return (0);
}

void	free_more_textures(t_game *game)
{
	if (game->textures->no)
	{
		if (game->textures->no->img)
			mlx_destroy_image(game->exe->mlx, game->textures->no->img);
		free(game->textures->no);
	}
	if (game->textures->so)
	{
		if (game->textures->so->img)
			mlx_destroy_image(game->exe->mlx, game->textures->so->img);
		free(game->textures->so);
	}
	if (game->textures->we)
	{
		if (game->textures->we->img)
			mlx_destroy_image(game->exe->mlx, game->textures->we->img);
		free(game->textures->we);
	}
	if (game->textures->ea)
	{
		if (game->textures->ea->img)
			mlx_destroy_image(game->exe->mlx, game->textures->ea->img);
		free(game->textures->ea);
	}
}

void	free_textures(t_game *game)
{
	if (!game->textures)
		return ;
	if (game->textures->f_value)
		free(game->textures->f_value);
	if (game->textures->c_value)
		free(game->textures->c_value);
	if (game->textures->so_path)
		free(game->textures->so_path);
	if (game->textures->no_path)
		free(game->textures->no_path);
	if (game->textures->we_path)
		free(game->textures->we_path);
	if (game->textures->ea_path)
		free(game->textures->ea_path);
	free_more_textures(game);
	free(game->textures);
}

void	finish_file(t_game *game)
{
	char	*line;

	line = get_next_line(game->file->filefd);
	while (line)
	{
		if (line)
			free(line);
		line = get_next_line(game->file->filefd);
	}
}
