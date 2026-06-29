/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saving_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-tuto <lle-tuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:34:01 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/09/30 11:10:56 by lle-tuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*ces deux fonctions permettent d'enregistrer la map dans la structure
dans game->file->map_matrix*/

static void	copying_map(int start, int end, t_game *game)
{
	int	i;

	i = 0;
	while (start <= end)
	{
		game->file->map_matrix[i] = ft_strdup(game->file->cubfile[start]);
		start++;
		i++;
	}
	game->file->map_matrix[i] = NULL;
}

void	saving_the_map(int j, t_game *game)
{
	int	start;
	int	end;

	end = j + game->file->m_size;
	start = j + 1;
	if (j == 0)
		free_exit("Error\nno map, you thought yo had me hehe\n", game, 2);
	game->file->map_matrix = malloc(sizeof(char *) * (game->file->m_size + 1));
	if (!game->file->map_matrix)
		free_exit("Malloc error\n", game, 1);
	copying_map(start, end, game);
}

/*ces deux fonctions permettent d'enregistrer le fichier complet dans
la structure dans game->file->cubfile*/
static int	sizing_file(t_game *game)
{
	char	*line;
	int		size;

	size = 0;
	game->file->filefd = working_file(game->file->filename, game);
	line = get_next_line(game->file->filefd);
	if (!line)
		free_exit("Error\n Empty or corrupted file.\n", game, 1);
	while (line)
	{
		free(line);
		size++;
		line = get_next_line(game->file->filefd);
	}
	close(game->file->filefd);
	game->file->filefd = -1;
	return (size);
}

void	saving_file(t_game *game)
{
	char	*line;
	int		i;

	i = 0;
	game->file->f_size = sizing_file(game);
	game->file->cubfile = malloc(sizeof(char *) * (game->file->f_size + 1));
	if (!game->file->cubfile)
		free_exit("Malloc error\n", game, 1);
	game->file->filefd = working_file(game->file->filename, game);
	line = get_next_line(game->file->filefd);
	while (line)
	{
		game->file->cubfile[i] = ft_strtrim(line, "\n\r");
		i++;
		free(line);
		line = get_next_line(game->file->filefd);
	}
	game->file->cubfile[i] = 0;
	close(game->file->filefd);
	game->file->filefd = -1;
}

/*verifie que le fichier s'ouvre et range le fd
dans la structure
*/
void	checking_and_storing_path(t_game *game, char *temp, int clue)
{
	if (opens_ok(temp) == -1)
		return (free(temp), free_exit(" won't open correctly\n", game, 2));
	if (clue == 1)
		game->textures->no_path = temp;
	else if (clue == 2)
		game->textures->so_path = temp;
	else if (clue == 3)
		game->textures->we_path = temp;
	else if (clue == 4)
		game->textures->ea_path = temp;
	else
		return (free(temp), free_exit("Error\nThese textures aren't right\n",
				game, 2));
}
