/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:21:19 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/01 12:54:27 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_macro(void)
{
	if (MINITILE > WIDTH / 34)
		return (1);
	if (MINITILE > HEIGHT / 18)
		return (1);
	if (FOV < 40 || FOV > 120)
		return (1);
	if (TILE < 1 || TILE > 60)
		return (1);
	return (0);
}

int	malloc_main(t_main *main)
{
	main->texture = ft_calloc(sizeof (t_texture), 1);
	if (!main->texture)
		return (error("Error\nCrash of Malloc.\n"), 1);
	main->floor = ft_calloc(sizeof (t_color), 1);
	if (!main->floor)
		return (error("Error\nCrash of Malloc.\n"), 1);
	main->ceiling = ft_calloc(sizeof (t_color), 1);
	if (!main->ceiling)
		return (error("Error\nCrash of Malloc.\n"), 1);
	main->ray = ft_calloc(sizeof (t_ray), 1);
	if (!main->ray)
		return (error("Error\nCrash of Malloc.\n"), 1);
	main->plyr = ft_calloc(sizeof (t_plyr), 1);
	if (!main->plyr)
		return (error("Error\nCrash of Malloc.\n"), 1);
	return (0);
}

int	main(int ac, char **av)
{
	t_main	*main;

	if (ac != 2)
		return (error("Error\nWrong number of parameter.\n"), -1);
	if (check_macro())
		return (error("Error\nWrong macro parameters.\n"), -1);
	main = ft_calloc(sizeof(t_main), 1);
	if (!main)
		return (error("Error\nCrash of Malloc.\n"), -1);
	if (check_file(av[1], main))
		return (free_all(main), -1);
	if (malloc_main(main))
		return (free_all(main), -2);
	if (getter(main))
		return (free_all(main), -3);
	if (get_map_bis(main))
		return (free_all(main), -4);
	if (get_map(main))
		return (free_all(main), -4);
	if (check_map(main->map, main))
		return (free_all(main), -5);
	init_player(main);
	if (exec(main))
		return (free_all(main), -6);
	return (close_win(main), 0);
}
