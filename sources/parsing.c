/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:25:24 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/02 14:04:24 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_border(char **map)
{
	size_t	y;
	size_t	x;

	y = 0;
	x = ft_strlen(map[0]);
	while (map[y])
	{
		if (map[y][0] != '1' || map[y][x - 1] != '1')
			return (error("Error\nThe map is incomplete.\n"), 1);
		y++;
	}
	x = 0;
	while (map[0][x])
	{
		if (map[0][x] != '1' || map[y - 1][x] != '1')
			return (error("Error\n The map is incomplete.\n"), 2);
		x++;
	}
	return (0);
}