/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:09:49 by beroy             #+#    #+#             */
/*   Updated: 2024/09/30 17:09:49 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate(t_main *main, int sign)
{
	static const double	rotation_step = (M_PI / 180) * ROT_SPEED;
	static const double	two_pi = 2 * M_PI;

	main->plyr->angle += sign * rotation_step;
	main->plyr->angle = fmod(main->plyr->angle, two_pi);
	if (main->plyr->angle < 0)
		main->plyr->angle += two_pi;
}
