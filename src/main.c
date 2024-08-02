/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:21:19 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/02 15:20:40 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_main	*main;

	main = calloc(sizeof (t_main), 1);
	if (ac != 2)
		return (error("Error\nWrong number of parameter.\n"), 1);
	if (check_file(av[1], main))
		return (2);
//	if (get_texture(main))
//		return (3);
//	if (get_color(main))
//		return (4);
//	if (get_map(main))
//		return (5);
//	exec(main);
//	return (free_all(main), 0);
}