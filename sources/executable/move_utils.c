/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:09:49 by beroy             #+#    #+#             */
/*   Updated: 2024/09/30 17:09:49 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate(t_main *main, int sign)
{
	main->plyr->angle += (M_PI / 180) * sign * ROT_SPEED;
	if (main->plyr->angle >= 2 * M_PI)
		main->plyr->angle -= 2 * M_PI;
	else if (main->plyr->angle < 0)
		main->plyr->angle += 2 * M_PI;
	raycaster(main);
	mlx_put_image_to_window(main->mlx, main->win, main->img.mlx_img, 0, 0);
}
