/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:58:32 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/03 11:49:37 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exec(t_main *main)
{
	main->mlx = mlx_init();
	if (!main->mlx)
		return (error("Error\nThe mlx has crash.\n"), 1);
	main->win = mlx_new_window(main->mlx, WIDTH, HEIGHT, "CUB3D");
	main->img.mlx_img = mlx_new_image(main->mlx, WIDTH, HEIGHT);
	main->img.addr = mlx_get_data_addr(main->img.mlx_img, &main->img.bpp, &main->img.line_len, &main->img.endian);
	raycaster(main);
	mlx_put_image_to_window(main->mlx, main->win, main->img.mlx_img, 0, 0);
	mlx_hook(main->win, 2, 1L << 0, key_hook, main);
	mlx_hook(main->win, 17, 0, close_win, main);
	mlx_loop(main->mlx);
	return (0);
}