/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:55:58 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/02 15:21:37 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_file(char *file, t_main *main)
{
	int i;
	int fd;

	(void)main;
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
//	main->fd = fd;
	return (0);
}

#include <string.h>

char	*path_text(char *gnl)
{
	int i = 0;
	while (gnl && gnl)
	{
		if (!strncmp(&gnl[i], "./", 2))
			return (&gnl[i]);
		i++;
	}
	return (NULL);
}

int	check_texture(char *gnl, int i, t_texture *texture)
{
	if (!strncmp(gnl, "NO", 2) && i == 0)
		texture->no = path_text(gnl);
	if (!strncmp(gnl, "SO", 2) && i == 1)
		texture->so = path_text(gnl);
	if (!strncmp(gnl, "WE", 2) && i == 2)
		texture->we = path_text(gnl);
	if (!strncmp(gnl, "EA", 2) && i == 3)
		texture->ea = path_text(gnl);
	if (i == 3 && (!texture->no || !texture->ea || ! texture->so || !texture->we))
		return (error("Error\nBad path to texture.\n"), 1);
	return (0);
}

int	get_texture(t_main *main)
{
	int		i;
	char	*gnl;

	i = 0;
	while (i < 4)
	{
		gnl = get_next_line(main->fd);
//		if (gnl && !ft_strcmp(gnl, "\n"))
//		{
//			free(gnl);
//			continue;
//		}
//		if (gnl && check_texture(gnl, i, main->texture))
//			return (1);
		i++;
	}
	return (0);
}

//int get_color(char *file, t_main *main)
//{
//
//}

//int get_map(char *file, t_main *main)
//{
//
//}
