/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:21:28 by grebrune          #+#    #+#             */
/*   Updated: 2025/01/31 16:44:15 by grebrune         ###   ########.fr       */
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

//4K
# define WIDTH 3840
# define HEIGHT 2160

//QHD
//# define WIDTH 2560
//# define HEIGHT 1440

//Full HD
//# define WIDTH 1920
//# define HEIGHT 1080

# define FOV 60
# define TILE 30
# define MOVE_SPEED 3
# define ROT_SPEED 3
# define SENSITIVITY 0.9
# define PLYR 0xFFFF4B1F
# define WALL 0xFF262626
# define BG 0xFFC9C9C9
# define MINITILE 12

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307

typedef struct s_pos
{
	int	pos_x;
	int	pos_y;
}	t_pos;

typedef struct s_plyr
{
	double	p_x;
	double	p_y;
	double	angle;
	float	fov_rd;
}	t_plyr;

typedef struct s_ray
{
	double	ray_ngl;
	double	distance;
	int		flag;
	double	p_x;
	double	p_y;
	double	h_x;
	double	h_y;
	double	v_x;
	double	v_y;
}	t_ray;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
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
	t_img	no_img;
	char	*so;
	t_img	so_img;
	char	*we;
	t_img	we_img;
	char	*ea;
	t_img	ea_img;
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
	int			keys[256];
	int			len;
	char		direction;
	size_t		pos_x;
	size_t		pos_y;
	double		inv_tile;
	double		img_width_inv_tile;
	int			map_h;
	int			map_w;
	t_color		*floor;
	t_color		*ceiling;
	t_texture	*texture;
}	t_main;

// cub_map_getter

int		get_map_bis(t_main *main);

// cub_utils

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_atoi(const char *nptr);

// cub_utils_2

size_t	tablen(char **tab);
void	init_player(t_main *main);
int		ft_strcmp(char *s1, const char *s2);
int		getter_end(t_main *main);
void	fix_address(t_texture *tex);

// checker

int		check_file(char *file, t_main *main);

// texture

int		path_text(char *gnl, char **fill);

// color

int		check_color(char *gnl, t_color *fill);

// map

int		get_map(t_main *main);

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

int		key_release(int keycode, t_main *main);
int		key_press(int keycode, t_main *main);
void	handle_movement(t_main *main);
int		mouse_move(int x, int y, t_main *main);
void	init_key(t_main *main);

// render

float	nor_ngl(float angle);
void	render_ray(t_main *main, int ray);

// minimap

void	mini_map(t_main *main);

// img_gen

void	img_pix_put(t_img *img, int x, int y, int color);
int		get_color(t_main *main, int flag);
void	draw_bg(t_main *main, int ray, int t_pix, int b_pix);

// raycaster

int		wall_hit(float x, float y, t_main *main);
double	get_h_inter(t_main *main, float angle);
double	get_v_inter(t_main *main, float angle);
int		raycaster(t_main *main);

// raycaster_utils

int		unit_circle(float angle, char c);
void	ray_hit_pos(t_main *main, int flag);
// move

void	move_f(t_main *main);
void	move_b(t_main *main);
void	move_l(t_main *main);
void	move_r(t_main *main);
void	rotate(t_main *main, int sign);
void	mouse_rotate(t_main *main, int sign);

// texture

int		tex_color(t_img *tex, int y, int x);
t_img	*wall_or(t_main *main);
char	**get_pix_addr(t_img *img, int x, int y);
int		get_tex(t_main *main, t_img *img, int i, double wall_h);

#endif
