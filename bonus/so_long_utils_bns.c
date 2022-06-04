/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bns.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqatim <oqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:36:20 by oqatim            #+#    #+#             */
/*   Updated: 2022/04/23 10:56:35 by oqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bns.h"

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

int	ft_exit(t_map *map)
{
	int	i;

	i = -1;
	while (map->map[++i])
		free(map->map[i]);
	free(map->map);
	mlx_destroy_window(map->mlx_ptr, map->mlx_win);
	exit(0);
}

void	check_extension_map(char *path)
{
	int	i;

	i = ft_strlen(path);
	if (path[i - 1] != 'r' || path[i - 2] != 'e'
		|| path[i - 3] != 'b' || path[i - 4] != '.')
	{
		printf("error map \n");
		exit(1);
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		so_long(av[1]);
	else
		printf("sda3 rass");
	return (0);
}
