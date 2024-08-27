
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:52:45 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/27 14:46:54 by grebrune         ###   ########.fr       */
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

	if (!main)
		return ;
	if (main->texture)
	{
		ft_free(main->texture->so);
		ft_free(main->texture->ea);
		ft_free(main->texture->we);
		ft_free(main->texture->no);
		ft_free(main->texture);
	}
	ft_free(main->ceiling);
	ft_free(main->floor);
	i = 0;
	while (main->map && main->map[i])
		ft_free(main->map[i++]);
	ft_free(main->map);
	ft_free(main);
	exit (0);
}

int	close_win(t_main *main)
{
	mlx_destroy_window(main->mlx, main->win);
	mlx_destroy_display(main->mlx);
	ft_free(main->mlx);
	free_all(main);
//	(void)main;
	return (0);
}
