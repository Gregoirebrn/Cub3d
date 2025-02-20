/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter_getter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:36:17 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/30 16:28:40 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	setter(t_main *main, char *gnl)
{
	if (!ft_strncmp(gnl, "F", 1) && check_color(&gnl[1], main->floor))
		return (1);
	if (!ft_strncmp(gnl, "C", 1) && check_color(&gnl[1], main->ceiling))
		return (2);
	if (!ft_strncmp(gnl, "NO", 2) && path_text(&gnl[2], &main->texture->no))
		return (3);
	if (!ft_strncmp(gnl, "SO", 2) && path_text(&gnl[2], &main->texture->so))
		return (4);
	if (!ft_strncmp(gnl, "WE", 2) && path_text(&gnl[2], &main->texture->we))
		return (5);
	if (!ft_strncmp(gnl, "EA", 2) && path_text(&gnl[2], &main->texture->ea))
		return (6);
	return (0);
}

int	find_char(t_main *main, char *gnl)
{
	int	i;

	i = 0;
	while (gnl && gnl[i])
	{
		if (gnl[i] == ' ')
			i++;
		else
			return (setter(main, &gnl[i]));
	}
	return (1);
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
		if (gnl && !ft_strcmp(gnl, "\n"))
		{
			ft_free(gnl);
			gnl = get_next_line(main->fd);
			continue ;
		}
		if (find_char(main, gnl))
			return (ft_free(gnl), 1);
		ft_free(gnl);
		count++;
		if (count == 6)
			break ;
		gnl = get_next_line(main->fd);
	}
	if (getter_end(main))
		return (2);
	return (fix_address(main->texture), 0);
}
