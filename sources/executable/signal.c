/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:38:10 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/03 14:29:38 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int keycode, t_main *main)
{
	if (keycode == 65307)
		close_win(main);
	if (keycode == 119 || keycode == 65362)
		move_f(main);
	if (keycode == 115 || keycode == 65364)
		move_b(main);
	if (keycode == 97)
		move_l(main);
	if (keycode == 100)
		move_r(main);
	if (keycode == 65361)
		rotate(main, -1);
	if (keycode == 65363)
		rotate(main, 1);
	return (0);
}
