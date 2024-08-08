/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:21:28 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/08 22:56:10 by grebrune         ###   ########.fr       */
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

typedef struct s_main
{
//	void		*mlx;
//	void		*win;
	int			fd;
	char		*filename;
	char		**map;
	char		direction;
	t_color		*floor;
	t_color		*ceiling;
	t_texture	*texture;
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
int		get_texture(t_main *main);
//color
int		get_color(t_main *main);
//map
int get_map(t_main *main);
//clear_error
void	error(char *str);
void	ft_free(void *data);
void	free_all(t_main *main);

#endif