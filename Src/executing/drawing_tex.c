/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_tex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-tuto <lle-tuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:11:21 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/10/01 09:38:57 by lle-tuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	check_texture(t_game *game, t_img *img)
{
	if (!img->img || !img->addr)
		free_exit("Texture loading failed\n", game, 1);
	if (img->bits_per_pixel != 32)
		free_exit("Texture of the wrong format\n", game, 1);
	if (img->width <= 0 || img->height <= 0)
		free_exit("Texture data is wrong\n", game, 1);
}

/*Calculates the exactposition where the ray hit the wall
side == 0 means its a vertical wall -> we look for the y position
floor(wallx) -> we only keep the partie fractionnaire
	->tells us where on the texture
we should take the pixel*/
static double	find_where_wall_was_hit(t_math *math, t_game *game)
{
	double	wallx;

	if (math->side == 0)
		wallx = game->player->posy + math->ray_len * math->raydiry;
	else
		wallx = game->player->posx + math->ray_len * math->raydirx;
	wallx -= floor(wallx);
	return (wallx);
}

/*Choses the pixel to load
& (img->height -1)
-> acts like a modulo if the height is a puissance de deux (64 is)
*/
static void	filling_texture_col(t_wall *wall, t_math *math, t_img *img)
{
	wall->texy = (int)wall->texpos & (img->height - 1);
	wall->texpos += wall->step;
	wall->texindex = wall->texy * img->width + wall->texx;
	wall->color = wall->tex_px[wall->texindex];
	if (math->side == 1)
		wall->color = (wall->color >> 1) & 0x7f7f7f;
}

/*casting the addresses to a uint32_t array allows us to treat
each pixel as an element of the array because we checked that 
the bbp was 32 earlier
then we just have to give a value to the screen array and it draws it*/
static void	making_buffer_and_column(t_wall *wall, t_game *game, t_math *math,
		t_img *img)
{
	int	y;

	y = 0;
	wall->tex_px = (uint32_t *)img->addr;
	wall->screen = (uint32_t *)game->exe->img->addr;
	while (y < wall->start)
	{
		wall->screen[y * game->exe->img->width
			+ wall->x_screen] = game->textures->c_color;
		y++;
	}
	while (y < wall->end)
	{
		filling_texture_col(wall, math, img);
		wall->screen[y * game->exe->img->width + wall->x_screen] = wall->color;
		y++;
	}
	while (y < game->exe->img->height)
	{
		wall->screen[y * game->exe->img->width
			+ wall->x_screen] = game->textures->f_color;
		y++;
	}
}

void	draw_texture(t_game *game, t_img *img, t_math *math, t_wall *wall)
{
	double	wallx;

	check_texture(game, img);
	wallx = find_where_wall_was_hit(math, game);
	if (wall->side == 'A')
		wall->texx = img->width - 1 - (int)(wallx * (double)img->width);
	else
		wall->texx = (int)(wallx * (double)img->width);
	wall->step = (double)img->height / (double)wall->line_height;
	wall->texpos = (wall->start - game->exe->img->height / 2 + wall->line_height
			/ 2) * wall->step;
	making_buffer_and_column(wall, game, math, img);
}
