/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 21:55:40 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/05 14:19:13 by grebrune         ###   ########.fr       */
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

char	*strdup_no_nl(const char *s)
{
	char	*dest;
	int		i;

	dest = ft_calloc(sizeof(char), (ft_strlen((char *)s) + 1));
	if (dest == NULL)
		return (dest);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
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
			*fill = strdup_no_nl(&gnl[i]);
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
