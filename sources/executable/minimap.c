/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:21:40 by beroy             #+#    #+#             */
/*   Updated: 2024/09/30 17:12:36 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	sqr_color(t_main *main, int x, int y, t_pos pos)
{
	int	sqr_x;
	int	sqr_y;

	sqr_x = pos.pos_x - 8 + x;
	sqr_y = pos.pos_y - 4 + y;
	if (x == 8 && y == 4)
		return (PLYR);
	if (sqr_x < 0 || sqr_y < 0)
		return (WALL);
	if (sqr_y >= main->map_h || sqr_x >= (int)ft_strlen(main->map[sqr_y]))
		return (WALL);
	if (main->map[sqr_y][sqr_x] == '1')
		return (WALL);
	if (main->map[sqr_y][sqr_x] == ' ')
		return (WALL);
	if (main->map[sqr_y][sqr_x] == 0)
		return (WALL);
	if (main->map[sqr_y][sqr_x] == '\n')
		return (WALL);
	return (BG);
}

void	draw_sqr(t_main *main, int x, int y, int pixel)
{
	int	i;
	int	j;

	j = y * MINITILE;
	while (j < (y + 1) * MINITILE)
	{
		i = x * MINITILE;
		while (i < (x + 1) * MINITILE)
		{
			img_pix_put(&main->img, i, j, pixel);
			i++;
		}
		j++;
	}
}

void	mini_map(t_main *main)
{
	t_pos	pos;
	int		x;
	int		y;

	pos.pos_x = floor(main->plyr->p_x / TILE);
	pos.pos_y = floor(main->plyr->p_y / TILE);
	y = 0;
	while (y < 9)
	{
		x = 0;
		while (x < 17)
		{
			draw_sqr(main, x, y, sqr_color(main, x, y, pos));
			x++;
		}
		y++;
	}
}
