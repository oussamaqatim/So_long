/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqatim <oqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:36:20 by oqatim            #+#    #+#             */
/*   Updated: 2022/04/23 10:31:15 by oqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	position_player(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->longeur)
	{
		j = -1;
		while (++j < map->largeur)
		{
			if (map->map[i][j] == 'P')
			{
				map->position_x = i;
				map->position_y = j;
			}
		}
	}
}

int	count_collect(t_map *map)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (++i < map->longeur)
	{
		j = -1;
		while (++j < map-> largeur)
		{
			if (map->map[i][j] == 'C')
				count++;
		}
	}
	return (count);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	str;

	if (n == -2147483648)
	{
		ft_putnbr_fd(n / 10, fd);
		write(fd, "8", 1);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		str = '0' + n % 10;
	}
	else
		str = '0' + n;
	write(fd, &str, 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		so_long(av[1]);
	else
		printf("sda3 rass");
}
