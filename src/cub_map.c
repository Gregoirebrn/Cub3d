/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 22:00:06 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/08 23:13:31 by grebrune         ###   ########.fr       */
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
	gnl = get_next_line(main->fd);
	while (gnl)
	{
		ft_free(gnl);
		gnl = get_next_line(main->fd);
		len++;
	}
	if (return_to_the_future(main))
		return (0);
	return (len);
}

int get_map(t_main *main)
{
	char	*gnl;
	int		i;
	int		len;

	i = 0;
	len = maplen(main);
	printf("maplen =%d-\n", len);
	main->map = ft_calloc(sizeof(char *), len);
	gnl = get_next_line(main->fd);
	while (gnl)
	{
		printf("-%s", gnl);
		main->map[i] = ft_strdup(gnl);
//		printf("-%s-", main->map[i]);
		ft_free(gnl);
		gnl = get_next_line(main->fd);
		i++;
	}
	return (0);
}
