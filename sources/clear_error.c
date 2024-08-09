/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:52:45 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/09 14:31:47 by grebrune         ###   ########.fr       */
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

void	ft_free(void *data)
{
	if (data)
		free(data);
	data = NULL;
}

void	free_all(t_main *main)
{
	int	i;

//	texture
	ft_free(main->texture->so);
	ft_free(main->texture->ea);
	ft_free(main->texture->we);
	ft_free(main->texture->no);
	ft_free(main->texture);
//	color
	ft_free(main->ceiling);
	ft_free(main->floor);
//	map
	i = 0;
	while (main->map && main->map[i])
		ft_free(main->map[i++]);
	ft_free(main->map);
//	struct
	ft_free(main);
}