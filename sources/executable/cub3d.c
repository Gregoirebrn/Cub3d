/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:58:32 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/28 15:50:35 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	bg_gen(t_main *main)
{
	int i;
	int j;

	i = 0;
	while (i < 1080)
	{
		j = 0;
		while (j < 1920)
		{
			if (i < 540)
				img_pix_put(&main->img, j, i, 0xff0000ff);
			else
				img_pix_put(&main->img, j, i, 0xffff0000);
			j++;
		}
		i++;
	}
}

void	map_gen(t_main *main)
{
	bg_gen(main);
	mlx_put_image_to_window(main->mlx, main->win, main->img.mlx_img, 0, 0);
}

int	exec(t_main *main)
{
	main->mlx = mlx_init();
	if (!main->mlx)
		return (error("Error\nThe mlx has crash.\n"), 1);
	main->win = mlx_new_window(main->mlx, 1920, 1080, "CUB3D");
	main->img.mlx_img = mlx_new_image(main->mlx, 1920, 1080);
	main->img.addr = mlx_get_data_addr(main->img.mlx_img, &main->img.bpp, &main->img.line_len, &main->img.endian);
	map_gen(main);
	mlx_hook(main->win, 2, 1L << 0, key_hook, main);
	mlx_hook(main->win, 17, 0, close_win, main);
	mlx_loop(main->mlx);
	return (0);
}