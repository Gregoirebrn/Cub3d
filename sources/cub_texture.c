/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 21:55:40 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/09 15:45:52 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	path_text(char *gnl, char **fill)
{
	int i;

	i = 0;
	if (*fill)
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
