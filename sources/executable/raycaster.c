/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:34:46 by beroy             #+#    #+#             */
/*   Updated: 2024/09/02 11:48:01 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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