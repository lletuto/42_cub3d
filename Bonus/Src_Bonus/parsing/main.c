/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-tuto <lle-tuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 10:59:32 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/09/25 10:59:32 by lle-tuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*
character tiles : N,S,E ou W
*/

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		free_exit("Game Malloc failed\n", NULL, 1);
	game_struct_init(game);
	if (argc != 2)
	{
		ft_putstr_fd("Error\nThis program takes a .cub file\n", 2);
		free_exit(NULL, game, 1);
	}
	parsing(argv[1], game);
	executing(game);
	free_exit(NULL, game, 0);
}
