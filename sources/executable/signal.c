/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:38:10 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/27 12:17:49 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int keycode, t_main *main)
{
//	(void)main;
	if (keycode == 65307)
	{
		error("Error\nexit code echap.\n");
		close_win(main);
	}
	return (0);
}
