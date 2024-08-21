/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:21:28 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/20 14:44:31 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//# include "mlx_linux/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "get_next_line.h"

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

//typedef struct s_utils
//{
//	char		**tmp;
//	char		direction;
//	size_t		pos_x;
//	size_t		pos_y;
//}	t_utils;

typedef struct s_main
{
//	void		*mlx;
//	void		*win;
	int			fd;
	char		*filename;
	char		**map;
	char		**tmp;
	char		direction;
	size_t		pos_x;
	size_t		pos_y;
	size_t		max_y;
	t_color		*floor;
	t_color		*ceiling;
	t_texture	*texture;
//	t_utils		*utils;
}	t_main;

//cub_utils
int		ft_strcmp(char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
int	ft_atoi(const char *nptr);
//checker
int		check_file(char *file, t_main *main);
//texture
int		path_text(char *gnl, char **fill);
//color
int	check_color(char *gnl, t_color *fill);
//map
int get_map(t_main *main);
//clear_error
void	error(char *str);
void	ft_free(void *data);
void	free_all(t_main *main);
//setter_getter
int		getter(t_main *main);
int		setter(t_main *main, char *gnl);

#endif