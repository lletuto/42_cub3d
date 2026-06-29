/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-tuto <lle-tuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 10:59:09 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/09/25 10:59:09 by lle-tuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*Verifie si le fichier s'ouvre renvoie le fd, il print aussi le nom
du fichier, utilise uniquement pour les textures*/
int	opens_ok(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(filename, 2);
		return (-1);
	}
	close(fd);
	return (0);
}

/*Opens a file and doesnt free the file name, exits in case of an error, used
for .cub file*/
int	working_file(char *filename, t_game *game)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(filename, 2);
		free_exit(" won't open correctly\n", game, 2);
	}
	return (fd);
}

/*Verifie si toutes les textures sont enregistrees et s'il
n'en manque pas*/
int	is_struct_full(t_game *game)
{
	if (!game->textures)
		return (0);
	if (!game->textures->so_path || !game->textures->no_path
		|| !game->textures->ea_path || !game->textures->we_path)
		return (0);
	if (!game->textures->f_value || !game->textures->c_value)
		return (0);
	return (1);
}

int	is_map_line(char *line)
{
	int	i;
	int	has_tile;

	has_tile = 0;
	if (is_empty_line(line))
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != ' ' && line[i] != 'S'
			&& line[i] != 'N' && line[i] != 'E' && line[i] != 'W')
			return (0);
		if (line[i] == '0' || line[i] == '1' || line[i] == 'S' || line[i] == 'N'
			|| line[i] == 'E' || line[i] == 'W')
			has_tile = 1;
		i++;
	}
	return (has_tile);
}

/*check si c'est un fichier .cub*/
void	is_cub_file(char *filename, t_game *game)
{
	int	i;

	i = ft_strlen(filename) - 1;
	while (i >= 0)
	{
		while (filename[i] == ' ')
			i--;
		if (!(filename[i] == 'b' && filename[i - 1] == 'u' && filename[i
					- 2] == 'c' && filename[i - 3] == '.'))
			free_exit("Error\nThis is not a .cub file.\n", game, 2);
		else
			return ;
		i--;
	}
}
