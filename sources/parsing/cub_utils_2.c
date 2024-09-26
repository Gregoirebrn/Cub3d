/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:37:14 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/26 15:33:11 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_main *main)
{
	main->plyr->p_x = main->pos_x * TILE + TILE / 2;
	main->plyr->p_y = main->pos_y * TILE + TILE / 2;
	main->plyr->fov_rd = (FOV * M_PI) / 180;
	if (main->direction == 'S')
		main->plyr->angle = M_PI_2;
	else if (main->direction == 'W')
		main->plyr->angle = M_PI;
	else if (main->direction == 'N')
		main->plyr->angle = 3 * M_PI_2;
	else
		main->plyr->angle = 2 * M_PI;
}

int	ft_strcmp(char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != 0 || s2[i] != 0)
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

size_t	tablen(char **tab)
{
	size_t	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}
