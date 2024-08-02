/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:52:45 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/02 14:04:24 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	write(2, str, i);
}

//void	free_all(t_main *main)
//{
//	texture
//	color
//	map
//}