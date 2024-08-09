/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:21:19 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/09 14:47:06 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	malloc_main(t_main *main)
{
	main = ft_calloc(sizeof(t_main), 1);
	if (!main)
		return (free_all(main), error("Error\nCrash of Malloc.\n"), exit(1), 1);
	main->texture = ft_calloc(sizeof (t_texture), 1);
	if (!main->texture)
		return (free_all(main), error("Error\nCrash of Malloc.\n"), exit(1), 1);
	main->floor = ft_calloc(sizeof (t_color), 1);
	if (!main->floor)
		return (free_all(main), error("Error\nCrash of Malloc.\n"), exit(1), 1);
	main->ceiling = ft_calloc(sizeof (t_color), 1);
	if (!main->ceiling)
		return (free_all(main), error("Error\nCrash of Malloc.\n"), exit(1), 1);
	return (0);
}

int	main(int ac, char **av)
{
	t_main	*main;

	if (ac != 2)
		return (error("Error\nWrong number of parameter.\n"), 1);
	main = NULL;
	malloc_main(main);
	if (check_file(av[1], main))
		return (free_all(main), 2);
	if (get_texture(main))
		return (free_all(main), 3);
	if (get_color(main))
		return (free_all(main), 4);
	if (get_map(main))
		return (free_all(main), 5);
//	exec(main);
	return (free_all(main), 0);
}