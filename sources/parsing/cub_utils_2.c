/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:37:14 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/03 14:00:29 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strcmp(char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != 0 || s2[i] != 0)
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

size_t	tablen(char **tab)
{
	size_t	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}

int	getter_end(t_main *main)
{
	if (!main->texture->no || !main->texture->ea || \
		! main->texture->so || !main->texture->we)
		return (error("Error\nBad path to texture.\n"), 2);
	if ((main->floor->b > 255 || main->floor->g > 255 || \
		main->floor->r > 255) || (main->ceiling->b > 255 || \
		main->ceiling->g > 255 || main->ceiling->r > 255))
		return (error("Error\nA color was not found.\n"), 3);
	return (0);
}
