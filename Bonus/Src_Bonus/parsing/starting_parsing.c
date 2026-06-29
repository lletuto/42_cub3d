/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-tuto <lle-tuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:09:46 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/09/29 14:26:46 by lle-tuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	finding_textures(t_game *game)
{
	int	i;

	i = 0;
	while (game->file->cubfile[i])
	{
		if (is_map_line(game->file->cubfile[i]) && is_struct_full(game))
			break ;
		else if (!is_map_line(game->file->cubfile[i]))
			texture_path(game->file->cubfile[i], game);
		else
			return (free_exit("Error\nMissing texture\n", game, 2));
		i++;
	}
	game->file->filefd = -1;
}

static void	reading_file(t_game *game)
{
	int	j;

	j = game->file->f_size - 1;
	while (is_empty_line(game->file->cubfile[j]) && j > 0)
		j--;
	if (!is_map_line(game->file->cubfile[j]))
		free_exit("Error\nThe map isn't here or valid\n", game, 2);
	while (is_map_line(game->file->cubfile[j]) && j > 0)
	{
		game->file->m_size++;
		j--;
	}
	if (j <= 0)
		free_exit("Error\nMissing half the info bestie\n", game, 2);
	if (!is_empty_line(game->file->cubfile[j]))
		free_exit("Error\nUnauthorised character ! Do better !\n", game, 2);
	saving_the_map(j, game);
	finding_textures(game);
}

static int	rgb_to_hexa(int *rgb)
{
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

static void	fill_hexa(t_textures *textures)
{
	textures->f_color = rgb_to_hexa(textures->f_value);
	textures->c_color = rgb_to_hexa(textures->c_value);
}

void	parsing(char *av, t_game *game)
{
	game->file->filename = ft_strdup(av);
	if (!game->file->filename)
		free_exit("Malloc error\n", game, 1);
	is_cub_file(game->file->filename, game);
	saving_file(game);
	reading_file(game);
	fill_hexa(game->textures);
	map_checking(game);
	grooming(game);
}
