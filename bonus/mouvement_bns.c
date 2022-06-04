/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement_bns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqatim <oqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:04:52 by oqatim            #+#    #+#             */
/*   Updated: 2022/04/22 16:49:19 by oqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bns.h"

int	ft_mouvement(int key, t_map *map)
{
	static int	k;

	ft_count_move(map);
	if (key == 2)
		ft_left(map, k);
	if (key == 0)
		ft_lisser(map, k);
	if (key == 1)
		ft_ltaht(map, k);
	if (key == 13)
		ft_lfoug(map, k);
	if (key == 53)
		exit(1);
	k++;
	return (0);
}

void	ft_left(t_map *map, int k)
{
	int	i;
	int	j;

	position_player(map);
	i = map->position_x;
	j = map->position_y;
	if (map->map[i][j + 1] == '0' || map->map[i][j + 1] == 'C')
	{
		map->map[i][j] = '0';
		map->map[i][j + 1] = 'P';
		parse_map(map, k);
	}
	else if (map->map[i][j + 1] == 'S')
		exit(1);
	else if (count_collect(map) == 0 && map->map[i][j + 1] == 'E')
	{
		exit(1);
	}
}

void	ft_lisser(t_map *map, int k)
{
	int	i;
	int	j;

	position_player(map);
	i = map->position_x;
	j = map->position_y;
	if (map->map[i][j - 1] == '0' || map->map[i][j - 1] == 'C')
	{
		map->map[i][j] = '0';
		map->map[i][j - 1] = 'P';
		parse_map(map, k);
	}
	else if (map->map[i][j - 1] == 'S')
		exit(1);
	else if (count_collect(map) == 0 && map->map[i][j - 1] == 'E')
	{
		exit(1);
	}
}

void	ft_ltaht(t_map *map, int k)
{
	int	i;
	int	j;		

	position_player(map);
	i = map->position_x;
	j = map->position_y;
	if (map->map[i + 1][j] == '0' || map->map[i + 1][j] == 'C')
	{
		map->map[i][j] = '0';
		map->map[i + 1][j] = 'P';
		parse_map(map, k);
	}
	else if (map->map[i + 1][j] == 'S')
		exit(1);
	else if (count_collect(map) == 0 && map->map[i + 1][j] == 'E')
	{
		exit(1);
	}
}

void	ft_lfoug(t_map *map, int k)
{
	int	i;
	int	j;		

	position_player(map);
	i = map->position_x;
	j = map->position_y;
	if (map->map[i - 1][j] == '0' || map->map[i - 1][j] == 'C')
	{
		map->map[i][j] = '0';
		map->map[i - 1][j] = 'P';
		parse_map(map, k);
	}
	else if (map->map[i - 1][j] == 'S')
		exit(1);
	else if (count_collect(map) == 0 && map->map[i - 1][j] == 'E')
	{
		exit(1);
	}
}
