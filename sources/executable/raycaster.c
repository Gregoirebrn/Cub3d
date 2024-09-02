/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:34:46 by beroy             #+#    #+#             */
/*   Updated: 2024/09/02 13:24:34 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	inter_check(float angle, float *inter, float* step, int horizon)
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
		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2))
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
	int 	pixel;

	x_step = TILE / tan(angle);
	y_step = TILE;
	y = floor(main->player->plyr_x / TILE) * TILE;
	pixel = inter_check(angle, &y, &y_step, 1);
	x = main->player->plyr_x + (y - main->player->plyr_y) / tan(angle);

}

void	raycaster(t_main *main)
{
	int		i;
	double	h_inter;
	double	v_inter;

	i = 0;
	main->ray->ray_ngl = main->player->angle - (main->player->fov_rd / 2);
	while (i < WIDTH)
	{
		main->ray->flag = 0;
		h_inter = ;
		v_inter = ;
		if (v_inter <= h_inter)
			main->ray->distance = v_inter;
		else
		{
			main->ray->distance = h_inter;
			main->ray->flag = 1;
		}
		// rendering should happen here
		i++;
		main->ray->ray_ngl += main->player->fov_rd / WIDTH;
	}
}