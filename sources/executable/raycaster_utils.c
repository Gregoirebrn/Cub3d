/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:01:02 by beroy             #+#    #+#             */
/*   Updated: 2024/09/30 17:02:25 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	unit_circle(float angle, char c)
{
	if (c == 'x')
	{
		if (angle > 0 && angle < M_PI)
			return (1);
	}
	else if (c == 'y')
	{
		if (angle > M_PI_2 && angle < 3 * M_PI_2)
			return (1);
	}
	return (0);
}

void	ray_hit_pos(t_main *main, int flag)
{
	if (flag == 0)
	{
		main->ray->p_x = main->ray->v_x;
		main->ray->p_y = main->ray->v_y;
	}
	else
	{
		main->ray->p_x = main->ray->h_x;
		main->ray->p_y = main->ray->h_y;
	}
}
