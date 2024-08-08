/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 21:55:40 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/08 21:55:40 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*path_text(char *gnl)
{
	int i;

	i = 0;
	while (gnl && gnl[i])
	{
		if (!ft_strncmp(&gnl[i], "./", 2))
			return (ft_strdup(&gnl[i]));
		i++;
	}
	return (NULL);
}

int	check_texture(char *gnl, int i, t_texture *texture)
{
	if (!ft_strncmp(gnl, "NO", 2) && i == 0)
		texture->no = path_text(gnl);
	if (!ft_strncmp(gnl, "SO", 2) && i == 1)
		texture->so = path_text(gnl);
	if (!ft_strncmp(gnl, "WE", 2) && i == 2)
		texture->we = path_text(gnl);
	if (!ft_strncmp(gnl, "EA", 2) && i == 3)
		texture->ea = path_text(gnl);
	if (i == 3 && (!texture->no || !texture->ea || ! texture->so || !texture->we))
		return (error("Error\nBad path to texture.\n"), 1);
	return (0);
}

int	get_texture(t_main *main)
{
	int		i;
	char	*gnl;

	i = 0;
	main->texture = ft_calloc(sizeof (t_texture), 1);
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
