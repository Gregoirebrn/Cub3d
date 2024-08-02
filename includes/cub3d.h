/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:21:28 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/02 15:10:16 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//# include "mlx_linux/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "get_next_line.h"

//typedef struct s_color
//{
//	unsigned int	r;
//	unsigned int	g;
//	unsigned int	b;
//}	t_color;
//
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
	char		**map;
	char		direction;
//	t_color		*ground;
//	t_color		*roof;
	t_texture	*texture;
}	t_main;

//cub_utils
int		ft_strcmp(char *s1, const char *s2);
//checker
int		check_file(char *file, t_main *main);
int		get_texture(t_main *main);
//clear_error
void	error(char *str);
void	free_all(t_main *main);

#endif