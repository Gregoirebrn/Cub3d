/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:22:36 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/30 16:36:40 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_item(char c)
{
	if (c != '0' && c != '1' && \
		c != 'N' && c != 'E' && \
		c != 'S' && c != 'W')
		return (1);
	return (0);
}

int	check_player(char **map, size_t x, size_t y)
{
	if ((x == 0 || map_item(map[y][x - 1])) ||
		(y == 0 || map_item(map[y - 1][x])))
		return (1);
	if ((ft_strlen(map[y]) < x || map_item(map[y][x + 1])) ||
		(tablen(map) == y + 1 || map_item(map[y + 1][x])))
		return (2);
	return (0);
}

int	check_char(char c, t_main *main, size_t x, size_t y)
{
	static int	direction = 0;

	if (c != '0' && c != '1' && \
		c != 'N' && c != 'E' && \
		c != 'S' && c != 'W' && \
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
		if (check_player(main->map, x, y))
			return (error("Error\nPlayer can't identify as a wall.\n"), 2);
	}
	return (0);
}

int	check_condition(char **map, t_main *main, size_t y, size_t x)
{
	if (check_char(map[y][x], main, x, y))
		return (1);
	if ((map[y][x] == '0' && \
		(x == 0 || map_item(map[y][x - 1]))) || \
		(map[y][x] == '0' && \
		(y == 0 || map_item(map[y - 1][x]))))
		return (error("Error\nThe map is not closed!\n"), 2);
	if ((map[y][x] == '0' && \
		(ft_strlen(map[y]) < x || \
		map_item(map[y][x + 1]))) || \
		(map[y][x] == '0' && \
		(tablen(map) == y + 1 || map_item(map[y + 1][x]))))
		return (error("Error\nThe map is not closed!\n"), 2);
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
			if (check_condition(map, main, y, x))
				return (1);
			x++;
		}
		if ((int)x > main->map_w)
			main->map_w = (int)x;
		y++;
	}
	main->map_h = (int)y;
	if (main->direction != 'N' && main->direction != 'E' && \
		main->direction != 'S' && main->direction != 'W')
		return (error("Error\nNone direction found in the map.\n"), 3);
	return (0);
}
