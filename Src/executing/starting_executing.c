/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting_executing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-tuto <lle-tuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 11:19:16 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/09/30 13:53:01 by lle-tuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	make_game(t_game *game)
{
	mlx_destroy_image(game->exe->mlx, game->exe->img->img);
	game->exe->img->img = mlx_new_image(game->exe->mlx, 1920, 1080);
	game->exe->img->addr = mlx_get_data_addr(game->exe->img->img,
			&game->exe->img->bits_per_pixel, &game->exe->img->line_length,
			&game->exe->img->endian);
	draw_game(game);
	mlx_put_image_to_window(game->exe->mlx, game->exe->win, game->exe->img->img,
		0, 0);
	return (0);
}

static void	opening_so_checking_ea(t_game *game)
{
	game->textures->ea->addr = mlx_get_data_addr(game->textures->ea->img,
			&game->textures->ea->bits_per_pixel,
			&game->textures->ea->line_length, &game->textures->ea->endian);
	if (!game->textures->ea->addr)
		free_exit("Error\nNO addr failed", game, 1);
	game->textures->so->img = mlx_xpm_file_to_image(game->exe->mlx,
			game->textures->so_path, &game->textures->so->width,
			&game->textures->so->height);
	if (!game->textures->so->img)
		free_exit("Error\nSO img failed", game, 1);
	game->textures->so->addr = mlx_get_data_addr(game->textures->so->img,
			&game->textures->so->bits_per_pixel,
			&game->textures->so->line_length, &game->textures->so->endian);
	if (!game->textures->so->addr)
		free_exit("Error\nSO addr failed", game, 1);
}

static void	opening_we_ea(t_game *game)
{
	game->textures->we = malloc(sizeof(t_img));
	if (!game->textures->we)
		free_exit("Malloc failed\n", game, 1);
	game->textures->we->img = mlx_xpm_file_to_image(game->exe->mlx,
			game->textures->we_path, &game->textures->we->width,
			&game->textures->we->height);
	if (!game->textures->we->img)
		free_exit("Error\nWE img failed", game, 1);
	game->textures->we->addr = mlx_get_data_addr(game->textures->we->img,
			&game->textures->we->bits_per_pixel,
			&game->textures->we->line_length, &game->textures->we->endian);
	if (!game->textures->we->addr)
		free_exit("Error\nWE addr failed", game, 1);
	game->textures->ea = malloc(sizeof(t_img));
	if (!game->textures->ea)
		free_exit("Malloc failed\n", game, 1);
	game->textures->ea->img = mlx_xpm_file_to_image(game->exe->mlx,
			game->textures->ea_path, &game->textures->ea->width,
			&game->textures->ea->height);
	if (!game->textures->ea->img)
		free_exit("Error\nEA img failed", game, 1);
	opening_so_checking_ea(game);
}

void	opening_textures(t_game *game)
{
	game->textures->no = malloc(sizeof(t_img));
	if (!game->textures->no)
		free_exit("Malloc failed\n", game, 1);
	game->textures->no->img = mlx_xpm_file_to_image(game->exe->mlx,
			game->textures->no_path, &game->textures->no->width,
			&game->textures->no->height);
	if (!game->textures->no->img)
		free_exit("Error\nNO img failed", game, 1);
	game->textures->no->addr = mlx_get_data_addr(game->textures->no->img,
			&game->textures->no->bits_per_pixel,
			&game->textures->no->line_length, &game->textures->no->endian);
	if (!game->textures->no->addr)
		free_exit("Error\nNO addr failed", game, 1);
	game->textures->so = malloc(sizeof(t_img));
	if (!game->textures->so)
		free_exit("Malloc failed\n", game, 1);
	opening_we_ea(game);
}

void	executing(t_game *game)
{
	game->exe->mlx = mlx_init();
	game->exe->img = malloc(sizeof(t_img));
	if (!game->exe->img)
		free_exit("img struct malloc failed\n", game, 1);
	game->exe->img->width = 1920;
	game->exe->img->height = 1080;
	if (!game->exe->mlx)
		free_exit("Init failed\n", game, 1);
	game->exe->win = mlx_new_window(game->exe->mlx, game->exe->img->width,
			game->exe->img->height, "cube");
	if (!game->exe->win)
		free_exit("Window creation failed\n", game, 1);
	game->exe->img->img = mlx_new_image(game->exe->mlx, game->exe->img->width,
			game->exe->img->height);
	game->exe->img->addr = mlx_get_data_addr(game->exe->img->img,
			&game->exe->img->bits_per_pixel, &game->exe->img->line_length,
			&game->exe->img->endian);
	mlx_put_image_to_window(game->exe->mlx, game->exe->win, game->exe->img->img,
		0, 0);
	opening_textures(game);
	mlx_hook(game->exe->win, 2, 1L << 0, key_handler, game);
	mlx_hook(game->exe->win, 17, 0, closing, game);
	mlx_loop_hook(game->exe->mlx, make_game, game);
	mlx_loop(game->exe->mlx);
}
