/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:14:36 by beroy             #+#    #+#             */
/*   Updated: 2024/09/30 17:08:25 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int	rgb_to_hex(t_color *color)
{
	return (255 << 24 | color->r << 16 | color->g << 8 | color->b << 0);
}

void	draw_bg(t_main *main, int ray, int t_pix, int b_pix)
{
	int	i;

	i = 0;
	while (i < t_pix)
	{
		img_pix_put(&main->img, ray, i, rgb_to_hex(main->ceiling));
		i++;
	}
	i = b_pix;
	while (i < HEIGHT)
	{
		img_pix_put(&main->img, ray, i, rgb_to_hex(main->floor));
		i++;
	}
}
