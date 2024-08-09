/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 21:55:40 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/09 14:44:16 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	path_text(char *gnl, char **fill)
{
	int i;

	i = 0;
	if (fill)
		return (error("Error\nmultiple description of a single texture.\n"), 1);
	while (gnl && gnl[i])
	{
		if (!ft_strncmp(&gnl[i], "./", 2))
		{
			*fill = ft_strdup(&gnl[i]);
			if (!*fill)
				return (error("Error\nCrash of Malloc.\n"), 2);
			return (0);
		}
		i++;
	}
	return (error("Error\n./ not found.\n"), 3);
}

int	check_texture(char *gnl, int i, t_texture *texture)
{
	return (0);
}

int	get_texture(t_main *main)
{
	int		i;
	char	*gnl;

	i = 0;
	while (i < 4)
	{
		gnl = get_next_line(main->fd);
		if (gnl && !ft_strcmp(gnl, "\n"))
		{
			ft_free(gnl);
			continue;
		}
		if (gnl && check_texture(gnl, i, main->texture))
			return (ft_free(gnl), 1);
		ft_free(gnl);
		i++;
	}
	return (0);
}
