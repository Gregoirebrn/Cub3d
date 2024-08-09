/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 21:52:50 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/09 15:35:56 by grebrune         ###   ########.fr       */
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
