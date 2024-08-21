/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 22:00:06 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/20 15:15:30 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	return_to_the_future(t_main *main)
{
	int fd;
	char *gnl;

	close(main->fd);
	fd = open(main->filename, O_RDONLY);
	if (fd == -1)
		return (error("Error\nCan't open file.\n"), 1);
	main->fd = fd;
	gnl = get_next_line(main->fd);
	while (gnl)
	{
		if (!ft_strncmp(gnl, "C", 1))
			return (ft_free(gnl), 0);
		ft_free(gnl);
		gnl = get_next_line(main->fd);
	}
	return (1);
}

int	maplen(t_main *main)
{
	char	*gnl;
	int		len;

	len = 0;
	if (return_to_the_future(main))
		return (0);
	gnl = get_next_line(main->fd);
	while (gnl)
	{
		if (!ft_strcmp(gnl, "\n"))
		{
			ft_free(gnl);
			gnl = get_next_line(main->fd);
			continue;
		}
//		printf("-%s", gnl);
		ft_free(gnl);
		gnl = get_next_line(main->fd);
		len++;
	}
	if (return_to_the_future(main))
		return (0);
	return (len + 1);
}

int	dup_map(t_main *main)
{
	int	x;
	int	y;

	y = 0;
	while (main->map && main->map[y])
		y++;
	main->max_y = y;
	main->tmp = ft_calloc(sizeof(char *), y + 1);
	if (main->tmp)
		return (free_all(main), 1);
	y = 0;
	while (main->map[y])
	{
		main->tmp[y] = ft_strdup(main->map[y]);
		if (main->tmp[y])
			return (free_all(main), 2);
	}
	main->map[y] = NULL;
	return (0);
}

int	find_wall(t_main *main, size_t y, size_t x)
{
	if (y > main->max_y || x > ft_strlen(main->tmp[y]) || main->tmp[y][x] == '\0')
		return (1);
	if (main->tmp[x][y] != '1' && main->tmp[y][x] != 'A' && main->tmp[y][x] != '\0')
	{
		main->tmp[x][y] = 'A';
		if (find_wall(main, y - 1, x))
			return (1);
		if (find_wall(main, y + 1, x))
			return (1);
		if (find_wall(main, y, x - 1))
			return (1);
		if (find_wall(main, y, x + 1))
			return (1);
	}
	return (0);
}

int	check_border(char **map, t_main *main)
{
	char	**tmp;

	if (dup_map(map))
		return (1);
	//call find_wall
	if (find_wall(main, main->pos_y, main->pos_x))
		return (error("Error\nThe map is not closed!"), 2);
	return (0);
}

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
			x++;
		}
		y++;
	}
	if (check_border(map, main))
		return (2);
	return (0);
}

int get_map(t_main *main)
{
	char	*gnl;
	int		i;

	i = 0;
	main->map = ft_calloc(sizeof(char *), maplen(main));
	if (!main->map)
		return (free_all(main), error("Error\nCrash of Malloc."), exit(1), 1);
	gnl = get_next_line(main->fd);
	while (gnl)
	{
		if (!ft_strcmp(gnl, "\n"))
		{
			ft_free(gnl);
			if (i == 0)
			{
				gnl = get_next_line(main->fd);
				continue ;
			}
			return (free_all(main), error("Error\nEmpty line in description of map."), exit(1), 1);
		}
		main->map[i] = ft_strdup(gnl);
		if (!main->map[i])
			return (free_all(main), ft_free(gnl), error("Error\nCrash of Malloc."), exit(1), 1);
		ft_free(gnl);
		gnl = get_next_line(main->fd);
		i++;
	}
	main->map[i] = NULL;
	if (check_map(main->map, main))
		return (1);
	return (0);
}
//		printf("-%s", gnl);
//		printf("-%s-", main->map[i]);
