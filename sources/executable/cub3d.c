/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:58:32 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/26 19:44:05 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exec(t_main *main)
{
//	(void)main;
	main->mlx = mlx_init();
	if (!main->mlx)
		return (error("Error\nThe mlx has crash."), 1);
	main->win = mlx_new_window(main->mlx, 60 * 10, 60 * 10, "CUB3D");
	mlx_hook(main->win, 2, 1L << 0, key_hook, &main);
	mlx_hook(main->win, 17, 1L << 0, close_win, &main);
	mlx_loop(main->mlx);
	return (0);
}