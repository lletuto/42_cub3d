/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-tuto <lle-tuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 10:14:10 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/09/29 17:10:27 by lle-tuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*Digital differential Analysis
c'est un methode connue(pas trop 
par moi j'avoue)
ou on considere que la carte devient
 une sorte de grille et on va chercher 
 a la dessiner
calcule la distance jusqu'a la prochaine 
ligne verticale ou horizontale si l'on suit 
le rayon.
Si rayDir == 0 alors la ligne est completement 
verticale ou completement horizontale
On ne calcule pas la distance exacte mais
 la distance qu'il y a techniquement entre deux cases en
fonction de l'orientation du rayon*/

/* create Raydir = permet de creer un rayon,
	ne gere pas encore la longueur en fonction des murs,
	fais juste tile size * 3*/

/*SteppingUp = SideDist est la distance exacte a parcourir
 pour atteindre la prochaine case*/

t_math	create_raydir(t_game *game, double planexpoint, int print_ray,
		int color)
{
	t_math	math;
	t_line	line;

	math.raydirx = game->player->dirx + game->player->planex * planexpoint;
	math.raydiry = game->player->diry + game->player->planey * planexpoint;
	dda(game, &math);
	line.startx = (int)(game->player->posx * TILE_SIZE);
	line.starty = (int)(game->player->posy * TILE_SIZE);
	line.endx = (int)(line.startx + math.raydirx * math.ray_len * TILE_SIZE);
	line.endy = (int)(line.starty + math.raydiry * math.ray_len * TILE_SIZE);
	line.color = color;
	if (print_ray)
		draw_line(game, line);
	return (math);
}

void	create_fov(t_game *game)
{
	float	x;

	x = -0.8;
	create_raydir(game, -1, 1, 0x800080);
	while (x <= 0.8)
	{
		create_raydir(game, x, 1, 0xff99ff);
		x += 0.2;
	}
	create_raydir(game, 1, 1, 0x800080);
}

int	mini_map(t_game *game)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (game->file->map_matrix[y])
	{
		x = 0;
		while (game->file->map_matrix[y][x])
		{
			if (game->file->map_matrix[y][x] == '1')
			{
				color = 0xff00ff;
				if (game->textures->c_color == color)
					color = 0xffc0cB;
				draw_square(game, (x) * TILE_SIZE, (y) * TILE_SIZE, color);
			}
			x++;
		}
		y++;
	}
	draw_player(game);
	create_fov(game);
	return (0);
}
