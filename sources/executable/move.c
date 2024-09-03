/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:05:32 by beroy             #+#    #+#             */
/*   Updated: 2024/09/03 15:18:42 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_f(t_main *main)
{
	main->plyr->p_x += round(cos(main->plyr->angle) * MOVE_SPEED);
	main->plyr->p_y += round(sin(main->plyr->angle) * MOVE_SPEED);
	raycaster(main);
	mlx_put_image_to_window(main->mlx, main->win, main->img.mlx_img, 0, 0);
}

void	move_b(t_main *main)
{
	main->plyr->p_x -= round(cos(main->plyr->angle) * MOVE_SPEED);
	main->plyr->p_y -= round(sin(main->plyr->angle) * MOVE_SPEED);
	raycaster(main);
	mlx_put_image_to_window(main->mlx, main->win, main->img.mlx_img, 0, 0);
}

void	move_l(t_main *main)
{
	main->plyr->p_x += round(sin(main->plyr->angle) * MOVE_SPEED);
	main->plyr->p_y -= round(cos(main->plyr->angle) * MOVE_SPEED);
	raycaster(main);
	mlx_put_image_to_window(main->mlx, main->win, main->img.mlx_img, 0, 0);
}

void	move_r(t_main *main)
{
	main->plyr->p_x -= round(sin(main->plyr->angle) * MOVE_SPEED);
	main->plyr->p_y += round(cos(main->plyr->angle) * MOVE_SPEED);
	raycaster(main);
	mlx_put_image_to_window(main->mlx, main->win, main->img.mlx_img, 0, 0);
}

void	rotate(t_main *main, int sign)
{
	main->plyr->angle += (M_PI / 180) * sign * ROT_SPEED;
	raycaster(main);
	mlx_put_image_to_window(main->mlx, main->win, main->img.mlx_img, 0, 0);
}
