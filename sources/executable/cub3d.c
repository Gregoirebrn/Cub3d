/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:58:32 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/30 16:57:11 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_tex(t_main *main, int state)
{
	if (state >= 3)
		mlx_destroy_image(main->mlx, main->texture->we_img.mlx_img);
	if (state >= 2)
		mlx_destroy_image(main->mlx, main->texture->so_img.mlx_img);
	if (state >= 1)
		mlx_destroy_image(main->mlx, main->texture->no_img.mlx_img);
	mlx_destroy_display(main->mlx);
	ft_free(main->mlx);
}

int	load_tex(t_main *main, t_img *img, char *tex)
{
	img->mlx_img = mlx_xpm_file_to_image(main->mlx, tex, &img->width,
			&img->height);
	if (img->mlx_img == NULL)
		return (1);
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp, &img->line_len,
			&img->endian);
	if (img->addr == NULL)
		return (1);
	return (0);
}

int	init_tex(t_main *main)
{
	int	state;

	state = 0;
	if (load_tex(main, &main->texture->no_img, main->texture->no) == 1)
		return (clear_tex(main, state), 1);
	state++;
	if (load_tex(main, &main->texture->so_img, main->texture->so) == 1)
		return (clear_tex(main, state), 1);
	state++;
	if (load_tex(main, &main->texture->we_img, main->texture->we) == 1)
		return (clear_tex(main, state), 1);
	state++;
	if (load_tex(main, &main->texture->ea_img, main->texture->ea) == 1)
		return (clear_tex(main, state), 1);
	return (0);
}

int	update_game(t_main *main)
{
	handle_movement(main);
	raycaster(main);
	mlx_put_image_to_window(main->mlx, main->win, main->img.mlx_img, 0, 0);
	return (0);
}

int	exec(t_main *main)
{
	init_key(main);
	main->mlx = mlx_init();
	if (!main->mlx)
		return (error("Error\nThe mlx has crash.\n"), 1);
	if (init_tex(main) == 1)
		return (error("Error\ntexture file has failed to load.\n"), 1);
	main->win = mlx_new_window(main->mlx, WIDTH, HEIGHT, "CUB3D");
	main->img.mlx_img = mlx_new_image(main->mlx, WIDTH, HEIGHT);
	main->img.addr = mlx_get_data_addr(main->img.mlx_img, &main->img.bpp,
			&main->img.line_len, &main->img.endian);
	raycaster(main);
	mlx_put_image_to_window(main->mlx, main->win, main->img.mlx_img, 0, 0);
	mlx_mouse_hide(main->mlx, main->win);
	mlx_hook(main->win, 6, 1L << 6, mouse_move, main);
	mlx_hook(main->win, 2, 1L << 0, key_press, main);
	mlx_hook(main->win, 3, 1L << 1, key_release, main);
	mlx_hook(main->win, 17, 0, close_win, main);
	mlx_loop_hook(main->mlx, update_game, main);
	mlx_loop(main->mlx);
	return (0);
}
