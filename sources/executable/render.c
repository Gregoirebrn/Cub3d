/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:57:40 by beroy             #+#    #+#             */
/*   Updated: 2024/09/24 17:38:09 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	nor_ngl(float angle)
{
	while (angle < 0 || angle > 2 * M_PI)
	{
		if (angle < 0)
			angle += 2 * M_PI;
		else if (angle > 2 * M_PI)
			angle -= 2 * M_PI;
	}
	return (angle);
}
//
//void	draw_wall(t_main *main, int ray, int t_pix, int b_pix)
//{
//	int	color;
//	int	i;
//
//	color = get_color(main, main->ray->flag);
//	i = t_pix;
//	while (i < b_pix)
//	{
//		img_pix_put(&main->img, ray, i, color);
//		i++;
//	}
//}

void	draw_wall(t_main *main, int ray, int t_pix, int b_pix, double wall_h)
{
	int	color;
	int	i;

	i = t_pix;
	while (i < b_pix)
	{
		color = get_tex(main, wall_or(main), i - t_pix, wall_h);
		img_pix_put(&main->img, ray, i, color);
		i++;
	}
}

void	render_ray(t_main *main, int ray)
{
	double	wall_h;
	double	b_pix;
	double	t_pix;

	main->ray->distance *= cos(nor_ngl(main->ray->ray_ngl - main->plyr->angle));
	wall_h = (TILE / main->ray->distance) * ((WIDTH / 2) / tan(main->plyr->fov_rd / 2));
	b_pix = (HEIGHT / 2) + (wall_h / 2);
	t_pix = (HEIGHT / 2) - (wall_h / 2);
	if (b_pix > HEIGHT)
		b_pix = HEIGHT;
	if (t_pix < 0)
		t_pix = 0;
	draw_wall(main, ray, t_pix, b_pix, wall_h);
	draw_bg(main, ray, t_pix, b_pix);
}
