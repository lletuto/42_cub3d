/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-tuto <lle-tuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 10:57:27 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/09/25 10:57:27 by lle-tuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../../minilibx-linux/mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>

# define TILE_SIZE 8
# define COLLAPSE 0.05f
# define MOVE_SPEED 0.05
# define PLAYER_SIZE 4
# define ROTSPEED 0.05

////////STRUcTURES////////

typedef struct s_math
{
	double	deltadisty;
	double	deltadistx;
	double	sidedistx;
	double	sidedisty;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		side;
	float	ray_len;
}			t_math;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_textures
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	t_img	*no;
	t_img	*so;
	t_img	*we;
	t_img	*ea;
	int		f_color;
	int		c_color;
	int		*f_value;
	int		*c_value;

}			t_textures;

typedef struct s_file
{
	char	*filename;
	char	**cubfile;
	char	**map_matrix;
	int		filefd;
	int		m_size;
	int		f_size;
}			t_file;

typedef struct s_player
{
	char	groom;
	float	posx;
	float	posy;
	float	dirx;
	float	diry;
	float	planex;
	float	planey;
}			t_player;

typedef struct s_exe
{
	void	*mlx;
	void	*win;
	t_img	*img;
}			t_exe;

typedef struct s_game
{
	int			oldx;
	t_exe		*exe;
	t_textures	*textures;
	t_file		*file;
	t_player	*player;
}				t_game;

typedef struct s_wall
{
	char		side;
	int			start;
	int			end;
	int			x_screen;
	int			line_height;
	int			texx;
	int			texy;
	int			texindex;
	double		step;
	double		texpos;
	uint32_t	color;
	uint32_t	*tex_px;
	uint32_t	*screen;

}				t_wall;

typedef struct s_line
{
	int	startx;
	int	starty;
	int	endx;
	int	endy;
	int	len;
	int	color;

}				t_line;

////////pARSING/////////

// free_exit
void	free_exit(char *errormsg, t_game *game, int exit_code);

// Utils
int		is_empty_line(char *line);
int		is_character_tile(char letter);
void	finish_file(t_game *game);
void	free_textures(t_game *game);

// file_check
void	is_cub_file(char *filename, t_game *game);
int		is_map_line(char *line);
int		is_struct_full(t_game *game);
int		working_file(char *filename, t_game *game);
int		opens_ok(char *filename);
void	checking_and_storing_path(t_game *game, char *temp, int clue);

// map reading
void	map_checking(t_game *game);

// Saving file
void	saving_file(t_game *game);
void	saving_the_map(int j, t_game *game);

// Struct init
void	grooming(t_game *game);
void	game_struct_init(t_game *game);

// paths & colors
void	valid_color_value(char *rgbline, t_game *game);
void	texture_path(char *line, t_game *game);

// Sarting parsing
void	parsing(char *av, t_game *game);

////////ExEcUTING/////////

// Utils
int		key_handler(int keycode, t_game *game);
int		closing(t_game *game);
int		mouse_handler(int x, int y, t_game *game);

// Drawing
void	draw_square(t_game *game, int x, int y, int color);
void	my_pixel_put(t_game *game, int x, int y, int color);
void	draw_line(t_game *game, t_line line);
void	draw_player(t_game *game);

// drawing tex
void	draw_texture(t_game *game, t_img *img, t_math *math, t_wall *wall);

// game
void	draw_game(t_game *game);

// Moving
void	rotate(t_game *game, double rotSpeed);
void	moving(t_game *game, int clue);

// DDA
void	dda(t_game *game, t_math *math);

// Mini map
void	dda(t_game *game, t_math *math);
t_math	create_raydir(t_game *game, double planexpoint, int print_ray,
			int color);
int		mini_map(t_game *game);

// Starting executing
void	executing(t_game *game);

#endif