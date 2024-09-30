/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:34:46 by beroy             #+#    #+#             */
/*   Updated: 2024/09/30 17:02:25 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	wall_hit(float x, float y, t_main *main)
{
	int	x_m;
	int	y_m;

	if (x < 0 || y < 0)
		return (0);
	x_m = floor(x / TILE);
	y_m = floor(y / TILE);
	if ((y_m >= main->map_h) || x_m >= main->map_w)
		return (0);
	if (main->map[y_m] && x_m <= (int)ft_strlen(main->map[y_m]))
		if (main->map[y_m][x_m] == '1')
			return (0);
	return (1);
}

int	inter_check(float angle, float *inter, float *step, int horizon)
{
	if (horizon == 1)
	{
		if (angle > 0 && angle < M_PI)
		{
			*inter += TILE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > M_PI_2 && angle < 3 * M_PI_2))
		{
			*inter += TILE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

double	get_h_inter(t_main *main, float angle)
{
	float	x;
	float	y;
	float	x_step;
	float	y_step;
	int		pixel;

	x_step = TILE / tan(angle);
	y_step = TILE;
	y = floor(main->plyr->p_y / TILE) * TILE;
	pixel = inter_check(angle, &y, &y_step, 1);
	x = main->plyr->p_x + (y - main->plyr->p_y) / tan(angle);
	if ((x_step > 0 && unit_circle(angle, 'y'))
		|| (x_step < 0 && !unit_circle(angle, 'y')))
		x_step *= -1;
	while (wall_hit(x, y - pixel, main))
	{
		x += x_step;
		y += y_step;
	}
	main->ray->h_x = x;
	main->ray->h_y = y;
	return (sqrt(pow(x - main->plyr->p_x, 2) + pow(y - main->plyr->p_y, 2)));
}

double	get_v_inter(t_main *main, float angle)
{
	float	x;
	float	y;
	float	x_step;
	float	y_step;
	int		pixel;

	x_step = TILE;
	y_step = TILE * tan(angle);
	x = floor(main->plyr->p_x / TILE) * TILE;
	pixel = inter_check(angle, &x, &x_step, 0);
	y = main->plyr->p_y + (x - main->plyr->p_x) * tan(angle);
	if ((y_step < 0 && unit_circle(angle, 'x'))
		|| (y_step > 0 && !unit_circle(angle, 'x')))
		y_step *= -1;
	while (wall_hit(x - pixel, y, main))
	{
		x += x_step;
		y += y_step;
	}
	main->ray->v_x = x;
	main->ray->v_y = y;
	return (sqrt(pow(x - main->plyr->p_x, 2) + pow(y - main->plyr->p_y, 2)));
}

void	raycaster(t_main *main)
{
	int		i;
	double	h_inter;
	double	v_inter;

	i = 0;
	main->ray->ray_ngl = main->plyr->angle - (main->plyr->fov_rd / 2);
	while (i < WIDTH)
	{
		main->ray->ray_ngl = nor_ngl(main->ray->ray_ngl);
		main->ray->flag = 0;
		h_inter = get_h_inter(main, main->ray->ray_ngl);
		v_inter = get_v_inter(main, main->ray->ray_ngl);
		if (v_inter <= h_inter)
			main->ray->distance = v_inter;
		else
		{
			main->ray->distance = h_inter;
			main->ray->flag = 1;
		}
		ray_hit_pos(main, main->ray->flag);
		render_ray(main, i);
		i++;
		main->ray->ray_ngl += main->plyr->fov_rd / WIDTH;
	}
	mini_map(main);
}
