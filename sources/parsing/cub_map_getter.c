/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map_getter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:22:40 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/22 22:38:43 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	return_to_the_future(t_main *main)
{
	int		fd;
	char	*gnl;

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
			continue ;
		}
		ft_free(gnl);
		gnl = get_next_line(main->fd);
		len++;
	}
	if (return_to_the_future(main))
		return (0);
	return (len + 1);
}

//int	get_map_extend(char *gnl, t_main *main, int i)
//{
//	if (!ft_strcmp(gnl, "\n"))
//	{
//		ft_free(gnl);
//		if (i == 0)
//		{
//			gnl = get_next_line(main->fd);
//			continue ;
//		}
//		return (error("Error\nEmpty line in description of map."), 1);
//	}
//	main->map[i] = ft_strdup(gnl);
//	if (!main->map[i])
//		return (ft_free(gnl), error("Error\nCrash of Malloc."), 1);
//	ft_free(gnl);
//	gnl = get_next_line(main->fd);
//}

int	get_map(t_main *main)
{
	char	*gnl;
	int		i;

	i = 0;
	main->map = ft_calloc(sizeof(char *), maplen(main));
	if (!main->map)
		return (error("Error\nCrash of Malloc."), 1);
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
			return (error("Error\nEmpty line in description of map."), 1);
		}
		main->map[i] = ft_strdup(gnl);
//		printf("%s", main->map[i]);
		if (!main->map[i])
			return (ft_free(gnl), error("Error\nCrash of Malloc."), 1);
		ft_free(gnl);
		gnl = get_next_line(main->fd);
		i++;
	}
	return (main->map[i] = NULL, 0);
}

//		printf("-%s", gnl);
//		printf("-%s-", main->map[i]);
//		printf("-%s", gnl);
