/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 21:52:50 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/09 15:28:41 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_line(char *gnl)
{
	int i;

	i = 2;
	while (gnl && gnl[i])
	{
		if (!(gnl[i] >= '0' && gnl[i] <= '9')
			&& gnl[i] != ','
			&& gnl[i] != ' '
			&& gnl[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	check_color(char *gnl, t_color *fill)
{
	int i;
	int filled;

	filled = 0;
	i = 0;
	if (check_line(gnl))
		return (1);
	while (gnl && gnl[i])
	{
		if (gnl[i] >= '0' && gnl[i] <= '9')
		{
			if (filled == 0)
				fill->r = ft_atoi(&gnl[i]);
			if (filled == 1)
				fill->g = ft_atoi(&gnl[i]);
			if (filled == 2)
				fill->b = ft_atoi(&gnl[i]);
			while (gnl[i] >= '0' && gnl[i] <= '9')
				i++;
			filled++;
		}
		i++;
	}
	if (filled != 3 || (fill->b > 255 || fill->g > 255 || fill->r > 255))
		return (3);
	return (0);
}

//int get_color(t_main *main)
//{
//
//}

int setter(t_main *main, char *gnl)
{
	if (!ft_strncmp(gnl, "F", 1) && check_color(gnl, main->floor))
		return (error("Error\nBad rgb, range [0,255].\n"), 1);
	if (!ft_strncmp(gnl, "C", 1) && check_color(gnl, main->ceiling))
		return (error("Error\nBad rgb, range [0,255].\n"), 2);
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

int getter(t_main *main)
{
	char	*gnl;

	gnl = get_next_line(main->fd);
	while (gnl)
	{
		if (gnl && !ft_strcmp(gnl, "\n"))
		{
			ft_free(gnl);
			continue;
		}
		if (setter(main, gnl))
			return (ft_free(gnl), free_all(main), exit(2), 1);
		ft_free(gnl);
		gnl = get_next_line(main->fd);
	}
	if (!main->texture->no || !main->texture->ea || ! main->texture->so || !main->texture->we)
		return (error("Error\nBad path to texture.\n"), 1);
	printf("-r%d-g%d-b%d-\n", main->floor->r, main->floor->g, main->floor->b);
	printf("-r%d-g%d-b%d-\n", main->ceiling->r, main->ceiling->g, main->ceiling->b);
	printf("-no%s-ea%s-so%s-we%s-\n",main->texture->no, main->texture->ea, main->texture->so, main->texture->we);
	return (0);
}

