/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:22:33 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/21 17:36:58 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	dest = malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (dest == NULL)
		return (dest);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((char *)s)[i++] = '\0';
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mal;

	mal = malloc(nmemb * size);
	if (mal == NULL)
		return (mal);
	ft_bzero(mal, nmemb * size);
	return (mal);
}

int	ft_atoi(const char *nptr)
{
	int	res;
	int	i;
	int	unit;

	res = 0;
	i = 0;
	unit = 0;
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		res = res * 10;
		res = res + nptr[i++] - 48;
		unit++;
		if (unit > 3)
			return (256);
	}
	return (res);
}
