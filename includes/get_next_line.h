/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:42:28 by grebrune          #+#    #+#             */
/*   Updated: 2023/11/21 18:14:04 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strcut(char *str);
char	*ft_strnext_line(char *str);
size_t	ft_charcmp(char *str, char c);
size_t	ft_strlen(const char *str);
void	ft_putstr(char *str);
char	*ft_lastline(char *str);
void	ft_memmove(char *str);
char	*ft_freenjoin(char *s1, char *s2);

#endif