/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 22:00:06 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/09 15:53:40 by grebrune         ###   ########.fr       */
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

int	check_map(char **map)
{
	size_t	y;
	size_t	x;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] != '0' && map[x][y] != '1' &&
				map[x][y] != 'N' && map[x][y] != 'E' &&
				map[x][y] != 'S' && map[x][y] != 'W' &&
				map[x][y] != ' ' && map[x][y] != '\n')
				return (error("Error\nWrong item in the map.\n"), 1);
			y++;
		}
		x++;
	}
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
	if (check_map(main->map))
		return (1);
	return (0);
}
//		printf("-%s", gnl);
//		printf("-%s-", main->map[i]);
