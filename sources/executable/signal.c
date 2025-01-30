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

void	handle_movement(t_main *main)
{
	if (main->keys[KEY_W])
		move_f(main);
	if (main->keys[KEY_S])
		move_b(main);
	if (main->keys[KEY_A])
		move_l(main);
	if (main->keys[KEY_D])
		move_r(main);
	if (main->keys[1])
		rotate(main, -1);
	if (main->keys[2])
		rotate(main, 1);
}

int	key_release(int keycode, t_main *main)
{
	if (keycode == KEY_W)
		main->keys[KEY_W] = 0;
	if (keycode == KEY_S)
		main->keys[KEY_S] = 0;
	if (keycode == KEY_A)
		main->keys[KEY_A] = 0;
	if (keycode == KEY_D)
		main->keys[KEY_D] = 0;
	if (keycode == KEY_LEFT)
		main->keys[1] = 0;
	if (keycode == KEY_RIGHT)
		main->keys[2] = 0;
	return (0);
}

int	key_press(int keycode, t_main *main)
{
	if (keycode == KEY_W)
		main->keys[KEY_W] = 1;
	if (keycode == KEY_S)
		main->keys[KEY_S] = 1;
	if (keycode == KEY_A)
		main->keys[KEY_A] = 1;
	if (keycode == KEY_D)
		main->keys[KEY_D] = 1;
	if (keycode == KEY_LEFT)
		main->keys[1] = 1;
	if (keycode == KEY_RIGHT)
		main->keys[2] = 1;
	if (keycode == KEY_ESC)
		close_win(main);
	return (0);
}

void	init_key(t_main *main)
{
	int	i;

	i = 0;
	while (i < 256)
	{
		main->keys[i] = 0;
		i++;
	}
}
