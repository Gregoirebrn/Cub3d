/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:21:28 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/02 16:38:18 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx_linux/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "get_next_line.h"

# define WIDTH 1920
# define HEIGHT 1080
# define FOV 60
# define TILE 30

typedef struct s_plyr
{
	int		p_x;
	int		p_y;
	double	angle;
	float	fov_rd;
	int		rot;
	int		l_r;
	int		u_d;
}	t_plyr;

typedef struct s_ray //the ray structure
{
	double	ray_ngl;
	double	distance;
	int		flag;
}	t_ray;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_texture
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_texture;

typedef struct s_main
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_ray		*ray;
	t_plyr		*plyr;
	int			fd;
	char		*filename;
	char		**map;
	int			len;
	char		direction;
	size_t		pos_x;
	size_t		pos_y;
	size_t		map_h;
	size_t		map_w;
	t_color		*floor;
	t_color		*ceiling;
	t_texture	*texture;
}	t_main;

// cub_utils

int		ft_strcmp(char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_atoi(const char *nptr);
size_t	tablen(char **tab);

// checker

int		check_file(char *file, t_main *main);

// texture

int		path_text(char *gnl, char **fill);

// color

int		check_color(char *gnl, t_color *fill);

// map

int 	get_map(t_main *main);

// clear_error

void	error(char *str);
void	ft_free(void *data);
void	free_all(t_main *main);
int		close_win(t_main *main);

// setter_getter

int		getter(t_main *main);
int		setter(t_main *main, char *gnl);

// map_checker

int		check_map(char **map, t_main *main);
int		maplen(t_main *main);

// executable

int		exec(t_main *main);

// signal

int		key_hook(int keycode, t_main *main);

#endif