/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:01:50 by schung            #+#    #+#             */
/*   Updated: 2022/09/03 14:50:08 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdbool.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

#define EXIT_FAILURE 	1
#define EXIT_SUCCESS 	0
#define WIDTH			1024
#define HEIGHT			512

// keycodes
# define MOVE_LEFT 		0
# define MOVE_RIGHT 	2
# define MOVE_DOWN 		1
# define MOVE_UP 		13
# define ROTATE_LEFT 	123
# define ROTATE_RIGHT 	124
# define ESCAPE 		53
# define SIZE_XPM 		64

typedef struct s_ray
{
	float	camera;
	double	dir_x;
	double	dir_y;
	double	delta_x;
	double	delta_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	int		side;
	double	perp_wall_dist;
}	t_ray;

typedef struct s_point 
{
	int	x;
	int	y;
	int z;
} t_point;

typedef struct s_textures
{
	int		east_wall[SIZE_XPM][SIZE_XPM];
	int		west_wall[SIZE_XPM][SIZE_XPM];
	int		north_wall[SIZE_XPM][SIZE_XPM];
	int		south_wall[SIZE_XPM][SIZE_XPM];
	int		doors[SIZE_XPM][SIZE_XPM];
	void	*tex_ptr[5];
	char	*tex_addr;
}	t_textures;


typedef enum e_tex
{
	north = 0,
	east = 1,
	west = 2,
	south = 3,
	door = 4,

}	t_tex;

typedef struct s_controls
{
	int	up;
	int	down;
	int	left;
	int	right;
	int	rotate_left;
	int	rotate_right;
	int	escape;
}	t_controls;

typedef struct s_wall
{
	int		top;
	int		bottom;
	int		x;
	double	step;
	double	position;
	int		direction;
	char	type;
}	t_wall;

typedef struct s_map 
{
	int 	columns;
	int		rows;
	char	**map;
} t_map;

typedef struct s_img
{
	void		*img_ptr;
	int			width;
	int			height;
	char		*addr;
	int			line_length;
	int			bits_per_pixel;
	int			endian;
	int			floor[3];
	int			ceiling[3];
	char		*tex_path[5];
	t_textures	textures;
} t_img;

typedef	struct s_data
{
	float		p_x;
	float		p_y;
	double		plane_x;
	double		plane_y;
	double		dir_x;
	double		dir_y;
	float		delta_x;
	float		delta_y;
	void		*mlx_ptr;
	void		*mlx_win;
	t_controls	controls;
	t_map		map;
	t_img		img;
	t_point		point;
	t_ray		ray;
	t_wall		wall;
} t_data;

//  init.c
int		create_rgb(int r, int g, int b);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		my_mlx_pixel_get(t_img *img, int x, int y);
int		get_color(char c);
int		get_minimap_color(t_data *data, int x, int y);

//	draw.c
int		draw_game(t_data *data);

//  events.c
int		exit_game(t_data *data, int exit_state);
int		key_release(int keycode, t_data *data);
int		key_press(int keycode, t_data *data);

//  textures.c
int		get_textures(t_data *data);
void	get_wall_pixels(t_img *img, int type);

//	rays.c
void	set_direction(t_data *data, t_ray *ray);
bool	is_wall(t_data *data, int x, int y, int p_x);
void	searching_wall(t_data *data, t_ray *ray, int p_x);
double	get_perp_wall_dist(t_data *data);
int		get_ray(t_data *data, int x);

//	wall.c
void	get_wall(t_data *data);
void	draw_walls(t_data *data, int x);

//	minimap.c
void	draw_25(t_img *img, int x, int y, int color);
void	draw_player(t_data *data);
int		draw_partial_minimap(t_data *data);
int		draw_minimap(t_data *data);

#endif