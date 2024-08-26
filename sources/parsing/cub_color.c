/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 21:52:50 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/26 16:17:51 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_line(char *gnl)
{
	int	i;

	i = 1;
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

void	check_color_extend(char *gnl, t_color *fill, int *filled, int *i)
{
	if (gnl[*i] >= '0' && gnl[*i] <= '9')
	{
		if (*filled == 0)
			fill->r = ft_atoi(&gnl[*i]);
		if (*filled == 1)
			fill->g = ft_atoi(&gnl[*i]);
		if (*filled == 2)
			fill->b = ft_atoi(&gnl[*i]);
		while (gnl[*i] >= '0' && gnl[*i] <= '9')
			*i = *i + 1;
		*filled = *filled + 1;
	}
}

int	check_color(char *gnl, t_color *fill)
{
	int	i;
	int	filled;

	filled = 0;
	i = 0;
	if (check_line(gnl))
		return (error("Error\nWrong format for color X r,g,b in rang [0,255].\n"), 1);
//	printf("-r%d-g%d-b%d-\n", fill->r, fill->g, fill->b);
	if (fill->r != 256 || fill->g != 256 || fill->b != 256)
		return (error("Error\nDouble declaration of a color.\n"), 2);
	while (gnl && gnl[i])
	{
		check_color_extend(gnl, fill, &filled, &i);
		i++;
	}
	if (filled != 3 || (fill->b > 255 || fill->g > 255 || fill->r > 255))
		return (error("Error\nBad rgb, range [0,255].\n"), 3);
	return (0);
}
