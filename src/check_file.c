/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:55:58 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/08 21:59:25 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_file(char *file, t_main *main)
{
	int	i;
	int	fd;

	i = 0;
	if (!file)
		return (error("Error\nEmpty file descriptor.\n"), 1);
	while (file && file[i])
		i++;
	if (i < 4 || ft_strcmp(&file[i - 4], ".cub"))
		return (error("Error\nBad file extension.\n"), 2);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (error("Error\nCan't open file.\n"), 1);
	if (read(fd, NULL, 0))
		return (perror(file), close(fd), 3);
	main->fd = fd;
	main->filename = file;
	return (0);
}
