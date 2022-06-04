/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqatim <oqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:35:32 by oqatim            #+#    #+#             */
/*   Updated: 2022/04/23 10:32:05 by oqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *str)
{
	char	*ptr;
	int		d;

	ptr = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!ptr)
		return (NULL);
	ptr[0] = 0;
	while (ft_backslash(ptr) == 0)
	{
		d = read(fd, ptr, BUFFER_SIZE);
		if (d == -1)
		{
			free (ptr);
			return (NULL);
		}
		if (d == 0)
			break ;
		ptr[d] = '\0';
		str = ft_strjoin(str, ptr);
	}
	free (ptr);
	return (str);
}

char	*ft_getline(char *str)
{
	char	*ptr;
	int		i;
	int		k;

	k = 0;
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
			i++;
	ptr = malloc(i + 1);
	while (k < i)
	{
		ptr[k] = str[k];
		k++;
	}
	ptr[k] = '\0';
	return (ptr);
}

char	*ft_save(char *str)
{
	char	*ptr;	
	int		s;
	int		c;

	s = 0;
	while (str[s] != '\n' && str[s] != '\0')
		s++;
	if (str[s] == '\n')
		s++;
	if (str[s] == '\0')
	{
		free(str);
		return (NULL);
	}
	c = ft_strlen(str) - s;
	ptr = ft_substr(str, s, c);
	free (str);
	return (ptr);
}

char	*get_next_line(int fd)
{
	char static	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read(fd, str);
	if (str == NULL)
		return (NULL);
	line = ft_getline(str);
	str = ft_save(str);
	return (line);
}
