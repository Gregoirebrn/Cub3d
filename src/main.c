/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:21:19 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/08 21:51:30 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_main	*main;

	main = ft_calloc(sizeof(t_main), 1);
	if (ac != 2)
		return (error("Error\nWrong number of parameter.\n"), ft_free(main), 1);
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