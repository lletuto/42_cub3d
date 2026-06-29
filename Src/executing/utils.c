/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaudrez <elaudrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:19:32 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/09/26 16:21:29 by elaudrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	key_handler(int keycode, t_game *game)
{
	if (keycode == 65307)
		free_exit(NULL, game, 2);
	if (keycode == 119)
		moving(game, 1);
	if (keycode == 115)
		moving(game, 2);
	if (keycode == 97)
		moving(game, 3);
	if (keycode == 100)
		moving(game, 4);
	if (keycode == 65361)
		rotate(game, -ROTSPEED);
	if (keycode == 65363)
		rotate(game, +ROTSPEED);
	return (0);
}

int	closing(t_game *game)
{
	free_exit(NULL, game, 0);
	return (0);
}
