/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:44:34 by beroy             #+#    #+#             */
/*   Updated: 2024/09/24 17:38:09 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int    tex_color(t_img *tex, int y, int x)
{
	if (x >= 0 && x < tex->width && y >= 0 && y < tex->height)
		return (*(int *) (tex->addr + (tex->line_len * y) + (x * tex->bpp / 8)));
	return (0x0);
}

t_img	*wall_or(t_main *main)
{
	if (main->ray->flag == 1)
	{
		if (main->ray->ray_ngl > 0 && main->ray->ray_ngl < M_PI)
			return (&main->texture->no_img);
		else
			return (&main->texture->so_img);
	}
	else
	{
		if (!(main->ray->ray_ngl > M_PI_2 && main->ray->ray_ngl < 3 * M_PI_2))
			return (&main->texture->we_img);
		else
			return (&main->texture->ea_img);
	}
}

char	**get_pix_addr(t_img *img, int x, int y)
{
	char    **addr;
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	addr = &pixel;
	return (addr);
}

int	get_abs_pos(t_main *main, char c)
{
	int pos;

	if (c == 'x')
		pos = main->plyr->p_x + cos(main->ray->ray_ngl) * main->ray->distance;
	else
		pos = main->plyr->p_y + sin(main->ray->ray_ngl) * main->ray->distance;
	return (pos);
}

int	get_tex(t_main *main, t_img *img, int i, double wall_h)
{
	int	x;
	int	y;
	int	pixel;

	if (wall_h > HEIGHT)
		i += (wall_h - HEIGHT) * 0.5;
	if (main->ray->flag == 1)
		x = (get_abs_pos(main, 'x') % TILE) * img->width / TILE;
	else
		x = (get_abs_pos(main, 'y') % TILE) * img->width / TILE;
	y = i * img->height / wall_h;
	pixel = tex_color(img, y, x);
	return (pixel);
}
