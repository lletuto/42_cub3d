/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-tuto <lle-tuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:04:07 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/09/30 18:35:33 by lle-tuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	stocking_path(int clue, char *line, t_game *game)
{
	int		i;
	char	*path;
	char	*temp;

	i = 0;
	while (line[i] && ft_isalpha(line[i]))
		i++;
	while (line[i] && (line[i] != '.'))
	{
		if (line[i] != ' ')
			free_exit("Error\nInvalid texture path\n", game, 2);
		i++;
	}
	if (!line[i] || (line[i + 1] && line[i + 1] != '/'))
		return (free_exit("Error\nInvalid texture path\n", game, 2));
	path = ft_substr(line, i + 2, ft_strlen(line) - (i + 2));
	temp = ft_strtrim(path, " \n\t\r");
	free(path);
	checking_and_storing_path(game, temp, clue);
}

/*remplit le tableau de int et verifie*/
static int	*atoi_tab(int *i_tab, char **c_tab, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (c_tab[i])
	{
		j = 0;
		i_tab[i] = ft_atoi(&c_tab[i][j]);
		if (i_tab[i] < 0 || i_tab[i] > 255 || is_empty_line(c_tab[i]))
		{
			free(i_tab);
			free_tab(&c_tab);
			free_exit("Error\nInvalid color values\n", game, 2);
		}
		i++;
	}
	if (i != 3)
	{
		free(i_tab);
		free_tab(&c_tab);
		free_exit("Error\nR G B is 3 values. Do better.\n", game, 2);
	}
	return (i_tab);
}

/*check si au dessus de int max--> pas entirement juste nb de char
mais de tt facon on refuse les valeurs superieures a 255*/
static int	*translating_tab(char **c_tab, t_game *game)
{
	int	i;
	int	j;
	int	*i_tab;

	i = 0;
	while (c_tab[i])
	{
		j = 0;
		while (c_tab[i][j])
		{
			if (!ft_isdigit(c_tab[i][j]) && c_tab[i][j] != ' '
				&& c_tab[i][j] != '\n' && c_tab[i][j] != '\0')
			{
				free_tab(&c_tab);
				free_exit("Error\nInvalid color value\n", game, 2);
			}
			j++;
		}
		i++;
	}
	i_tab = malloc(sizeof(int) * i);
	if (!i_tab)
		return (free_tab(&c_tab), free_exit("Error\nMalloc failed\n", game, 1),
			NULL);
	return (atoi_tab(i_tab, c_tab, game));
}

/*On divise les trois donnees a l'aide de split et on les envoie vers une
fonction qui va traduire les char en chaine de caractere.*/
static void	stocking_color(int clue, char *line, t_game *game)
{
	int		i;
	char	**tab;
	char	*rgbvalues;

	i = 0;
	while (line[i] && (line[i] != 'C' && line[i] != 'F'))
		i++;
	rgbvalues = ft_substr(line, i + 1, ft_strlen(line) - (i + 1));
	if (is_empty_line(rgbvalues))
	{
		free(rgbvalues);
		free_exit("Error\nMissing color values\n", game, 2);
	}
	valid_color_value(rgbvalues, game);
	tab = ft_split(rgbvalues, ',');
	free(rgbvalues);
	if (clue == 1)
		game->textures->f_value = translating_tab(tab, game);
	else if (clue == 2)
		game->textures->c_value = translating_tab(tab, game);
	free_tab(&tab);
}

/*divise les infos du .cub selon les chemin vers un fichier et les couleurs
indiquees en RGB,
	les clues permettent de ne pas avoir a refaire de strncmp plus tard*/
void	texture_path(char *line, t_game *game)
{
	if ((!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "N ", 2))
		&& !game->textures->no_path)
		stocking_path(1, line, game);
	else if ((!ft_strncmp(line, "SO ", 3) || !ft_strncmp(line, "S ", 2))
		&& !game->textures->so_path)
		stocking_path(2, line, game);
	else if ((!ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "W ", 2))
		&& !game->textures->we_path)
		stocking_path(3, line, game);
	else if ((!ft_strncmp(line, "EA ", 3) || !ft_strncmp(line, "E ", 2))
		&& !game->textures->ea_path)
		stocking_path(4, line, game);
	else if (!ft_strncmp(line, "F ", 2) && !game->textures->f_value)
		stocking_color(1, line, game);
	else if (!ft_strncmp(line, "C ", 2) && !game->textures->c_value)
		stocking_color(2, line, game);
	else if (line[0] == '\n' || line[0] == '\r' || line[0] == '\0')
		return ;
	else
		free_exit("Error\nUnexpected line\n", game, 2);
}
