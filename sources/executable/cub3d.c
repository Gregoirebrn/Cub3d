/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:58:32 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/04 14:37:59 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_tex(t_main *main, t_img *img, char *tex)
{
	img->mlx_img = mlx_new_image(main->mlx, TEX_W, TEX_H);
	mlx_xpm_file_to_image(main->mlx, tex, 0, 0);
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp, &img->line_len, &img->endian);
	if (img->addr == NULL)
		return (1);
	return (0);
}

int	init_tex(t_main *main)
{
	if (load_tex(main, &main->texture->no_img, main->texture->no) == 1)
		return (1);
	if (load_tex(main, &main->texture->so_img, main->texture->so) == 1)
		return (1);
	if (load_tex(main, &main->texture->we_img, main->texture->we) == 1)
		return (1);
	if (load_tex(main, &main->texture->ea_img, main->texture->ea) == 1)
		return (1);
	return (0);
}

int	exec(t_main *main)
{
	main->mlx = mlx_init();
	if (!main->mlx)
		return (error("Error\nThe mlx has crash.\n"), 1);
	main->win = mlx_new_window(main->mlx, WIDTH, HEIGHT, "CUB3D");
	main->img.mlx_img = mlx_new_image(main->mlx, WIDTH, HEIGHT);
	main->img.addr = mlx_get_data_addr(main->img.mlx_img, &main->img.bpp, &main->img.line_len, &main->img.endian);
	if (init_tex(main) == 1)
		return (error("Error\ntexture file has failed to load.\n"), 1);
	raycaster(main);
	mlx_put_image_to_window(main->mlx, main->win, main->img.mlx_img, 0, 0);
	mlx_hook(main->win, 2, 1L << 0, key_hook, main);
	mlx_hook(main->win, 17, 0, close_win, main);
	mlx_loop(main->mlx);
	return (0);
}