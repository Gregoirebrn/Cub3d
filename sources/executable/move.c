/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:05:32 by beroy             #+#    #+#             */
/*   Updated: 2024/09/27 14:32:54 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_hit(t_main *main, double x_move, double y_move)
{
	if (wall_hit(main->plyr->p_x + x_move, main->plyr->p_y, main) == 0)
		return (0);
	if (wall_hit(main->plyr->p_x, main->plyr->p_y + y_move, main) == 0)
		return (0);
	if (wall_hit(main->plyr->p_x + x_move, main->plyr->p_y + y_move, main) == 0)
		return (0);
	return (1);
}

void	move_f(t_main *main)
{
	double	x_move;
	double	y_move;

	x_move = cos(main->plyr->angle) * MOVE_SPEED;
	y_move = sin(main->plyr->angle) * MOVE_SPEED;
	if (move_hit(main, x_move, y_move) == 1)
	{
		main->plyr->p_x += x_move;
		main->plyr->p_y += y_move;
	}
	raycaster(main);
	mlx_put_image_to_window(main->mlx, main->win, main->img.mlx_img, 0, 0);
}

void	move_b(t_main *main)
{
	double	x_move;
	double	y_move;

	x_move = -1 * cos(main->plyr->angle) * MOVE_SPEED;
	y_move = -1 * sin(main->plyr->angle) * MOVE_SPEED;
	if (move_hit(main, x_move, y_move) == 1)
	{
		main->plyr->p_x += x_move;
		main->plyr->p_y += y_move;
	}
	raycaster(main);
	mlx_put_image_to_window(main->mlx, main->win, main->img.mlx_img, 0, 0);
}

void	move_l(t_main *main)
{
	double	x_move;
	double	y_move;

	x_move = sin(main->plyr->angle) * MOVE_SPEED;
	y_move = -1 * cos(main->plyr->angle) * MOVE_SPEED;
	if (move_hit(main, x_move, y_move) == 1)
	{
		main->plyr->p_x += x_move;
		main->plyr->p_y += y_move;
	}
	raycaster(main);
	mlx_put_image_to_window(main->mlx, main->win, main->img.mlx_img, 0, 0);
}

void	move_r(t_main *main)
{
	double	x_move;
	double	y_move;

	x_move = -1 * sin(main->plyr->angle) * MOVE_SPEED;
	y_move = cos(main->plyr->angle) * MOVE_SPEED;
	if (move_hit(main, x_move, y_move) == 1)
	{
		main->plyr->p_x += x_move;
		main->plyr->p_y += y_move;
	}
	raycaster(main);
	mlx_put_image_to_window(main->mlx, main->win, main->img.mlx_img, 0, 0);
}
