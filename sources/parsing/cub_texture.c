/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 21:55:40 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/27 17:58:22 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_xpm(char *gnl)
{
	int	i;

	i = 0;
	while (gnl && gnl[i])
		i++;
	if (i < 5 || ft_strcmp(&gnl[i - 5], ".xpm\n"))
		return (1);
	return (0);
}

int	path_text(char *gnl, char **fill)
{
	int	i;

	i = 0;
	if (*fill)
		return (error("Error\nmultiple description of a single texture.\n"), 1);
	while (gnl && gnl[i])
	{
		if (gnl[i] != ' ' && gnl[i] != '\n')
		{
			*fill = ft_strdup(&gnl[i]);
			if (!*fill)
				return (error("Error\nCrash of Malloc.\n"), 2);
			if (check_xpm(gnl))
				return (error("Error\nBad texture extension.\n"), 3);
			return (0);
		}
		i++;
	}
	return (error("Error\nTexture path not found.\n"), 3);
}
