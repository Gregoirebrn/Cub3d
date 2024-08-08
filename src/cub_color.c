/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 21:52:50 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/08 21:52:50 by grebrune         ###   ########.fr       */
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
	if (filled != 3)
		return (3);
	return (0);
}

int get_color(t_main *main)
{
	int		i;
	char	*gnl;

	i = 0;
	main->floor = ft_calloc(sizeof (t_color), 1);
	main->ceiling = ft_calloc(sizeof (t_color), 1);
	while (i < 4)
	{
		gnl = get_next_line(main->fd);
		if (gnl && !ft_strcmp(gnl, "\n"))
		{
			ft_free(gnl);
			continue;
		}
		if (!ft_strncmp(gnl, "F", 1) && i == 0 && check_color(gnl, main->floor))
			return (error("Error\nBad rgb, range [0,255].\n"), ft_free(gnl), 1);
		if (!ft_strncmp(gnl, "C", 1) && i == 1 && check_color(gnl, main->ceiling))
			return (error("Error\nBad rgb, range [0,255].\n"), ft_free(gnl), 2);
		ft_free(gnl);
		i++;
	}
	if (main->floor->b > 255 || main->floor->g > 255 || main->floor->r > 255)
		return (error("Error\nBad rgb, range [0,255].\n"), 3);
	if (main->ceiling->b > 255 || main->ceiling->g > 255 || main->ceiling->r > 255)
		return (error("Error\nBad rgb, range [0,255].\n"), 4);
//	printf("-r%d-g%d-b%d-\n", main->floor->r, main->floor->g, main->floor->b);
//	printf("-r%d-g%d-b%d-\n", main->ceiling->r, main->ceiling->g, main->ceiling->b);
	return (0);
}

