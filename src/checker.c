/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:55:58 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/08 18:04:14 by grebrune         ###   ########.fr       */
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
	main->fd = fd;
	return (0);
}

char	*path_text(char *gnl)
{
	int i;

	i = 0;
	while (gnl && gnl[i])
	{
		if (!ft_strncmp(&gnl[i], "./", 2))
			return (ft_strdup(&gnl[i]));
		i++;
	}
	return (NULL);
}

int	check_texture(char *gnl, int i, t_texture *texture)
{
	if (!ft_strncmp(gnl, "NO", 2) && i == 0)
		texture->no = path_text(gnl);
	if (!ft_strncmp(gnl, "SO", 2) && i == 1)
		texture->so = path_text(gnl);
	if (!ft_strncmp(gnl, "WE", 2) && i == 2)
		texture->we = path_text(gnl);
	if (!ft_strncmp(gnl, "EA", 2) && i == 3)
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
	main->texture = ft_calloc(sizeof (t_texture), 1);
	while (i < 4)
	{
		gnl = get_next_line(main->fd);
		if (gnl && !ft_strcmp(gnl, "\n"))
		{
			ft_free(gnl);
			continue;
		}
		if (gnl && check_texture(gnl, i, main->texture))
			return (1);
		ft_free(gnl);
		i++;
	}
	return (0);
}

int	check_color(char *gnl, t_color *fill)
{
	int i;
	int filled;

	filled = 0;
	i = 0;
	while (gnl && gnl[i])
	{
		if (gnl[i] >= '0' && gnl[i] <= '9')
		{
			if (filled == 0)
				fill->r = ft_atoi(&gnl[i]);
			if (filled == 1)
				fill->g = ft_atoi(&gnl[i]);
			if (filled == 2)
				fill->b = ft_atoi(&gnl[i]);
			filled++;
		}
	}
	if (fill->b < 0 || fill->g < 0 || fill->r < 0)
		return (error("Error\nBad rgb.\n"), 1);
	if (fill->b > 255 || fill->g > 255 || fill->r > 255)
		return (error("Error\nBad rgb.\n"), 1);
	return (0);
}

int get_color(t_main *main)
{
	int		i;
	char	*gnl;

	i = 0;
	main->floor = ft_calloc(sizeof (t_color), 1);
	main->ceiling = ft_calloc(sizeof (t_color), 1);
	while (i < 4)
	{
		gnl = get_next_line(main->fd);
		if (gnl && !ft_strcmp(gnl, "\n"))
		{
			ft_free(gnl);
			continue;
		}
		if (!ft_strncmp(gnl, "F", 1) && i == 0)
			check_color(gnl, main->floor);
		if (!ft_strncmp(gnl, "C", 1) && i == 1)
			texture->so = path_text(gnl);
		ft_free(gnl);
		i++;
	}
	return (0);
}

//int get_map(char *file, t_main *main)
//{
//
//}
