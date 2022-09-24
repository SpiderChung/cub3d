/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:38:03 by schung            #+#    #+#             */
/*   Updated: 2022/09/24 19:38:03 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../../libft/libft.h"

# define MAP_CHAR "NSEW2 01"
# define IN_CHAR "NSEW20"
# define BORDER_CHAR "1 "
# define HERO_CHAR "NSEW"
# define DOOR_CHAR '2'

/*
# define NO_ARG 1
# define TOO_MANY_ARG 2
# define ERROR_FILE_TYPE 3
*/
typedef struct arrays_s
{
	char	*str;
	char	**colors;
	char	**textures;
	char	**map;
	int		flag_colors;
	int		flag_textures;
	int		flag_in;
	int		flag_hero;
	int		hpx;
	int		hpy;
	char	direction;
	int		empty_string;
	int		map_height;
	int		map_width;
	char	arch[9];
	int		f[3];
	int		c[3];
	int		ii;
	int		jj;
	int		kk;
	char	cc;
}	t_arrays;

typedef struct wwall_s
{
	char	*we;
	char	*ea;
	char	*no;
	char	*so;
}	t_wwall;

typedef struct colors_s
{
	int	floor[3];
	int	ceiling[3];
}	t_colors;

typedef struct map_s
{
	char	**lines;
	int		width;
	int		heigth;
	char	*char_list;
}	t_map;

typedef struct hero_position_s
{
	int		x;
	int		y;
	char	direction;
}	t_hero_position;

typedef struct validate_s
{
	t_map			map;
	t_colors		colors;
	t_hero_position	hero;
	t_wwall			wall;
}	t_validate;

/*------------validation.c----------------------*/
void		validate_free(t_arrays *ar);
t_validate	*validate_init(t_arrays *ar);
t_validate	*validate(char **argv, int argc);

/*------------init_arrays.c----------------------*/
t_arrays	read_file(int fdmap);
void		initial_arrays(t_arrays *ar);
void		init_arrays(t_arrays *arrays, char *str, int i);
void		init_check(t_arrays *ar, char *str, char *temp, int *i);

/*------------init2.c----------------------*/
void		init_textures2(t_arrays *arrays, char *temp);
void		init_textures(t_arrays *arrays, char *str, int *i);
void		init_colors2(t_arrays *ar, char *temp);
void		init_colors(t_arrays *arrays, char *str, int *i);

/*------------init_map.c----------------------*/
void		init_map2(t_arrays *ar, char *str, char *temp, int *i);
void		init_map(t_arrays *arrays, char *str, int *i);

/*------------utilites.c----------------------*/
void		ft_str_trim(char **str);
int			char_in_str(char c, char *str, int i);
int			ft_count_str(char *str);
int			ft_count_str_array(t_arrays *ar);
//int			ft_count_str_array(char **str);
//int			search_max_string(char **array);
int			search_max_string(t_arrays *ar);

/*------------utilites2.c----------------------*/
char		*get_file(int fd);
int			error(char *str);

/*------------check_map.c----------------------*/
void		check_map(t_arrays *ar);
int			check_map_quadro(t_arrays *arrays);
void		map_print(t_arrays *ar);
void		map_normalize(t_arrays *ar);
void		ft_prokrust(t_arrays *ar, int i);

/*------------check_map2.c----------------------*/
void		check_border(t_arrays *ar);
void		check_map_in(t_arrays *ar);
int			ft_leacks_corner(t_arrays *ar);
void		ft_flag_set(t_arrays *ar);
void		check_door(t_arrays *ar);

/*------------check_colors.c----------------------*/
int			ft_num(char *tstr, int k, int *i);
char		*temp_prepare(t_arrays *ar, int l, int i);
void		check_c_fornull(t_arrays *ar);
void		check_colors(t_arrays *ar);

/*------------check_textures.c----------------------*/
void		check_t_fornull(t_arrays *ar);
void		check_textures(t_arrays *ar);

#endif
