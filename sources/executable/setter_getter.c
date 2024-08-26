/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter_getter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:36:17 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/26 17:07:43 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	setter(t_main *main, char *gnl)
{
	if (!ft_strncmp(gnl, "F", 1) && check_color(gnl, main->floor))
		return (1);
	if (!ft_strncmp(gnl, "C", 1) && check_color(gnl, main->ceiling))
		return (2);
	if (!ft_strncmp(gnl, "NO", 2) && path_text(gnl, &main->texture->no))
		return (3);
	if (!ft_strncmp(gnl, "SO", 2) && path_text(gnl, &main->texture->so))
		return (4);
	if (!ft_strncmp(gnl, "WE", 2) && path_text(gnl, &main->texture->we))
		return (5);
	if (!ft_strncmp(gnl, "EA", 2) && path_text(gnl, &main->texture->ea))
		return (6);
	return (0);
}

void	init_color(t_main *main)
{
	if (main->floor)
	{
		main->floor->r = 256;
		main->floor->g = 256;
		main->floor->b = 256;
	}
	if (main->ceiling)
	{
		main->ceiling->r = 256;
		main->ceiling->g = 256;
		main->ceiling->b = 256;
	}
}

int	getter(t_main *main)
{
	char	*gnl;
	int		count;

	init_color(main);
	gnl = get_next_line(main->fd);
	count = 0;
	while (gnl)
	{
//		printf("%s", gnl);
		if (gnl && !ft_strcmp(gnl, "\n"))
		{
			ft_free(gnl);
			gnl = get_next_line(main->fd);
			continue ;
		}
		if (setter(main, gnl))
			return (ft_free(gnl), 1);
		ft_free(gnl);
		count++;
		if (count == 6)
			break;
		gnl = get_next_line(main->fd);
	}
//	printf("-r%d-g%d-b%d-\n", main->floor->r, main->floor->g, main->floor->b);
//	printf("-r%d-g%d-b%d-\n", main->ceiling->r, main->ceiling->g, main->ceiling->b);
//	printf("-no%s-ea%s-so%s-we%s-\n",main->texture->no, main->texture->ea, main->texture->so, main->texture->we);
	if (!main->texture->no || !main->texture->ea || \
		! main->texture->so || !main->texture->we)
		return (error("Error\nBad path to texture.\n"), 2);
	if ((main->floor->b > 255 || main->floor->g > 255 || main->floor->r > 255) || \
		(main->ceiling->b > 255 || main->ceiling->g > 255 || main->ceiling->r > 255))
		return (error("Error\nA color was not found.\n"), 3);
//	printf("-----------------------------\n");
	return (0);
}

