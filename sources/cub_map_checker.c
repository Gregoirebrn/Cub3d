/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:22:36 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/21 16:30:48 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_char(char c, t_main *main, size_t x, size_t y)
{
	static int	direction = 0;

	if (c != '0' && c != '1' &&
		c != 'N' && c != 'E' &&
		c != 'S' && c != 'W' &&
		c != ' ' && c != '\n')
		return (error("Error\nWrong item in the map.\n"), 1);
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
	{
		main->direction = c;
		main->pos_x = x;
		main->pos_y = y;
		direction++;
		if (direction > 1)
			return (error("Error\nMultiple direction in the map.\n"), 2);
	}
	return (0);
}

int	map_item(char c)
{
	if (c != '0' && c != '1' &&
		c != 'N' && c != 'E' &&
		c != 'S' && c != 'W')
		return (1);
	return (0);
}

int	check_map(char **map, t_main *main)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (check_char(map[y][x], main, x, y))
				return (1);
			if (map[y][x] == '0' && x != 0 && map_item(map[y][x - 1]))
				return (error("Error\nThe map is not closed!\n"), 2);
			if (map[y][x] == '0' && y != 0 && map_item(map[y - 1][x]))
				return (error("Error\nThe map is not closed!\n"), 2);
			if (map[y][x] == '0' && map[y][x + 1] && map_item(map[y][x + 1]))
				return (error("Error\nThe map is not closed!\n"), 2);
			if (map[y][x] == '0' && map[y + 1][x] && map_item(map[y + 1][x]))
				return (error("Error\nThe map is not closed!\n"), 2);
			x++;
		}
		y++;
	}
	return (0);
}
