/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-tuto <lle-tuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:08:22 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/09/30 17:00:53 by lle-tuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	free_file(t_game *game)
{
	if (!game->file)
		return ;
	if (game->file->filename)
		free(game->file->filename);
	if (game->file->filefd > 0)
	{
		finish_file(game);
		close(game->file->filefd);
	}
	if (game->file->map_matrix)
		free_tab(&game->file->map_matrix);
	if (game->file->cubfile)
		free_tab(&game->file->cubfile);
	free(game->file);
}

static void	free_player(t_game *game)
{
	if (!game->player)
		return ;
	free(game->player);
}

static void	free_img(t_game *game)
{
	if (game->exe->img->img)
		mlx_destroy_image(game->exe->mlx, game->exe->img->img);
	free(game->exe->img);
}

static void	free_exe(t_game *game)
{
	if (!game->exe)
		return ;
	if (game->exe->img)
		free_img(game);
	if (game->exe->mlx)
	{
		if (game->exe->win)
			mlx_destroy_window(game->exe->mlx, game->exe->win);
		mlx_destroy_display(game->exe->mlx);
		free(game->exe->mlx);
	}
	free(game->exe);
}

void	free_exit(char *errormsg, t_game *game, int exit_code)
{
	if (errormsg)
		ft_putstr_fd(errormsg, 2);
	if (game)
	{
		free_textures(game);
		free_file(game);
		free_player(game);
		free_exe(game);
		free(game);
	}
	exit(exit_code);
}
